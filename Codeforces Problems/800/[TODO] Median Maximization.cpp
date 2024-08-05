// Median Maximization (https://codeforces.com/problemset/problem/1566/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
typedef long long ll;
 
void solve(ll S, ll N) {
    if (S % N == 0) {
        cout << (S/N) << endl;
    } else {
        cout << (S/N + 1) << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        ll N, S;
        cin >> N >> S;

        solve(S, N);
    }
    
    return 0;
}