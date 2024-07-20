// Restoring the Duration of Tasks (https://codeforces.com/problemset/problem/1690/C)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
// duration[i] = finish[i] - actual_start[i]

void solve(vector<int>& S, vector<int>& F, int N) {
    int i = 0;
    int curr_time = S[i++];
    for (int j = 0; j < N; j++) {
        int dur = F[j] - curr_time;
        cout << dur << " ";

        if (i < N) {
            curr_time = max(S[i], F[j]);
            i++;
        } else {
            curr_time = F[j];
        }
    }

    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> S(N), F(N);
        for (int i = 0; i < N; i++)
            cin >> S[i];

        for (int i = 0; i < N; i++)
            cin >> F[i];

        solve(S, F, N);
    }
    
    return 0;
}