// Remove Prefix (https://codeforces.com/problemset/problem/1714/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)

const int MAX_N = 2 * 1e5;

void solve(vector<int>& A, int N) {
    vector<int> table(MAX_N + 1, 0);

    int i = N-1;
    while (i >= 0) {
        int a = A[i];
        if (table[a] != 0)
            break;

        table[a] = 1; 
        i--;
    }
    
    cout << (i+1) << endl;
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