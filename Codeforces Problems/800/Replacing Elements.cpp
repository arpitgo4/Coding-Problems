// Replacing Elements (https://codeforces.com/problemset/problem/1473/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
/**
 * A[i] = A[j] + A[k]
 * A[i] <= D
 * 
 * A[j] + A[k] <= D
 * 
 * Two sum problem,
 * A[j] <= (D - A[k])
 * 
 * For every A[j], if there exists a number in the set which is (D-A[])
 * 
 * Inequality equations can be solved by Binary Search.
 */

void solve(vector<int>& A, int N, int D) {
    sort(A.begin(), A.end());

    bool can_do = true;
    if (A[0] > D)
        can_do = (A[1] + A[2] <= D);
    if (A[1] > D)
        can_do = (A[0] + A[2] <= D);
    for (int i = 2; i < N; i++)
        if (A[i] > D)
            can_do = (A[0] + A[1] <= D);

    cout << (can_do ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, D;
        cin >> N >> D;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
    
        solve(A, N, D);
    }
    
    return 0;
}