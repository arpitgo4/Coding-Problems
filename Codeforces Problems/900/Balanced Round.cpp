// Balanced Round (https://codeforces.com/problemset/problem/1850/D)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
void solve(vector<int>& A, int N, int K) {
    sort(A.begin(), A.end());

    int max_w = 1, j = 0;
    for (int i = 1; i < N; i++) {
        if (abs(A[i]-A[i-1]) > K)
            j = i;
        
        max_w = max(max_w, i-j+1);
    }

    cout << (N-max_w) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
    
        solve(A, N, K);
    }
    
    return 0;
}