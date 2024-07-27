// Honest Coach (https://codeforces.com/problemset/problem/1360/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
/**
 * Naive/Brute-force approach,
 * Generate all possible 2 subsets from given set and minimize the
 * given function
 * Time: O(2^N)
 * Space: O(N)
 * 
 * Greedy approach,
 * 
 */

void solve(vector<int>& A, int N) {
    sort(A.begin(), A.end());

    int min_diff = INT_MAX;
    for (int i = 1; i < N; i++) 
        min_diff = min(min_diff, A[i]-A[i-1]);

    cout << min_diff << endl;
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