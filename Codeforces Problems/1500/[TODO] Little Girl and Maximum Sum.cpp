// Little Girl and Maximum Sum (https://codeforces.com/problemset/problem/276/C)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
/**
 * Based on the query pattern,
 * 1. Count for each index how many times it will be 
 *    touched by all queries. Use difference array for
 *    this.
 * 2. Distribute array elements in non-increasing order
 *    and assign in array by non-decreasing order of touch
 *    counts.
 * 3. Build prefix sum table for reordered array
 * 4. Calculate sum of all the query values
 */

typedef long long ll;

void solve(vector<int>& A, int N) {
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int l, r;
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
    }
    
    return 0;
}