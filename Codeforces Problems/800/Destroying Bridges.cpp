// Destroying Bridges (https://codeforces.com/problemset/problem/1944/A)
 
#include <iostream>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(int N, int K) {
    cout << (K >= N-1 ? 1 : N) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        solve(N, K);
    }
    
    return 0;
}