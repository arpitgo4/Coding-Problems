// Advantage (https://codeforces.com/problemset/problem/1760/C)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)

void solve(vector<int>& A, int N) {
    int max_1 = 0, max_2 = 0, max_1_idx = -1; 
    for (int i = 0; i < N; i++) {
        int a = A[i];
        if (a > max_1) {
            max_2 = max_1;
            max_1 = a;
            max_1_idx = i;
        } else if (a > max_2)
            max_2 = a;
    }
    
    for (int i = 0; i < N; i++) {
        if (i == max_1_idx)
            cout << A[i] - max_2 << " ";
        else cout << A[i] - max_1 << " ";
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

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N);
    }
    
    return 0;
}