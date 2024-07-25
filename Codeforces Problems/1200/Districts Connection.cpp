// Districts Connection (https://codeforces.com/problemset/problem/1433/D)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)

/**
 * Need to find a permutation that satisfies problem's constraints! 
 * Time: O(N!)
 * This will TLE!
 * 
 * We can use Bitmask DP here.
 * Time: O(2^N)
 * But, this will TLE!
 * 
 * Pick a district and then pick next not-similar district
 * This hints towards a backtracking algorithm with a dynamic
 * data-structure
 * 
 * Take a greedy approach or ad-hoc problem solving will do this
 * in linear/quasi-linear time.
 * 
 * We can pick the next non-equal district from all the choices.
 * Any district can be re-used any number of times.
 * 
 * We can just pick two distict gang districts and keep connecting
 * other districts among both.
*/

void solve(vector<int>& A, int N) {
    int a_idx = -1, a = 0, b = 0, b_idx = -1;
    for (int i = 0; i < N; i++) {
        if (a == 0) {
            a = A[i];
            a_idx = i;
        } else if (b == 0 && a != A[i]) {
            b = A[i];
            b_idx = i;
        }
    }

    if (a == 0 || b == 0) {
        cout << "NO" << endl;
        return;
    }
    else cout << "YES" << endl;

    for (int i = 1; i < N; i++) {
        if (A[i] != a)
            cout << (i+1) << " " << (a_idx+1) << endl;
        else cout << (i+1) << " " << (b_idx+1) << endl;
    }
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