// Halloumi Boxes (https://codeforces.com/problemset/problem/1903/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(vector<int>& A, int N, int K) {
    bool is_non_decr = true;
    for (int i = 1; i < N; i++) {
        if (A[i-1] > A[i])
            is_non_decr = false;
    }

    if (is_non_decr || K > 1)
        cout << "YES" << endl;
    else cout << "NO" << endl;
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
