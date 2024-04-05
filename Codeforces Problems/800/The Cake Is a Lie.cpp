// The Cake Is a Lie (https://codeforces.com/problemset/problem/1519/B)
 
#include <iostream>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)

bool solve(int N, int M, int K) {
    return (N * M - 1) == K;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        bool possible = solve(N, M, K);
        cout << (possible ? "YES" : "NO") << endl;
    }
    
    return 0;
}