// All Distinct (https://codeforces.com/problemset/problem/1692/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

/**
 * Final result depends on the parity of N, count & (N-count)
 * 
 * (N, count) => (rest of the duplicates)
 * (even, even) => even => (count)
 * (even, odd) => odd => (count-1)
 * (odd, even) => odd => (count-1)
 * (odd, odd) => even => (count)
 */

const int MAX_VAL = 1e4;

void solve(vector<int>& A, int N) {
    vector<int> table(MAX_VAL, 0);

    int count = 0;
    for (int a : A) {
        if (table[a] == 0)
            count++;

        table[a] = 1;
    }

    if ((N % 2 == 0 && count % 2 == 0) || (N % 2 == 1 && count % 2 == 1))
        cout << count << endl;
    else cout << (count-1) << endl;
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