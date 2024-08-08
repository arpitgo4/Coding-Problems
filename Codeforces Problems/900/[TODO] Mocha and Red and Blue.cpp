 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

// R: 0, B: 1
void solve(string& S, int N) {
    vector<int> A(N, -1);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R')
            A[i] = 0;
        else if (S[i] == 'B')
            A[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        if (A[i] == -1) {
            if (i > 0 && A[i-1] == A[i])
                A[i] = !A[i-1];
            else if (i < N && A[i+1] == A[i])
                A[i] = !A[i+1];
        }
    }

    for (int i = 0; i < N; i++)
        cout << (A[i] == 0 ? 'R' : 'B');
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

        string S;
        cin >> S;

        solve(S, N);
    }
    
    return 0;
}