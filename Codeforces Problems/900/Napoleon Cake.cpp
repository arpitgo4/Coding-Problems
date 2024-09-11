// Napoleon Cake (https://codeforces.com/problemset/problem/1501/B)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
/**
 * We need efficient range updates for this problem
 * 
 * 1. Range updates will be done without reads
 * 2. Reading is only required at the end of all updates
 * 
 * Difference Array can be used here!
 */

void solve(vector<int>& A, int N) {
    vector<int> diff(N, 0);
    for (int i = 0; i < N; i++) {
        if (A[i] > 0) {
            int start = max(0, i-A[i]+1);
            int end = i;

            diff[start] += 1;
            if (end+1 < N)
                diff[end+1] -= 1;
        }
    }

    cout << (diff[0] > 0 ? 1 : 0) << " ";
    for (int i = 1; i < N; i++) {
        diff[i] += diff[i-1];
        cout << (diff[i] > 0 ? 1 : 0) << " ";
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