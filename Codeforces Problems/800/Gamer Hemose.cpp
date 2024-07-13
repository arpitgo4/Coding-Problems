// Gamer Hemose (https://codeforces.com/problemset/problem/1592/A)
 
#include <iostream>
#include <vector>
 
using namespace std;

typedef long long ll;
 
// Time: O(N)
// Space: O(1)
 
/**
 * H = (B1.x + B2.y)
 * 
 * x == (y+1)
 * x == y
 * 
 * 
 * H = B1.(y+1) + B2.y
 * H = (B1 + B2).y + B1
 * (H - B1)/(B1 + B2) = y
 * x = y+1;                     // result
 * 
 * H = (B1 + B2).x
 * H/(B1 + B2) = x            // result
 */

void solve(vector<ll>& A, ll N, ll H) {
    ll max_1 = -1, max_2 = -1;
    for (ll a : A) {
        if (a > max_1) {
            max_2 = max_1;
            max_1 = a;
        } else if (a > max_2)
            max_2 = a;
    }

    ll count = 0;
    ll sum = max_1 + max_2;
    if (H % sum == 0)
        count = (H / sum) * 2;
    else if (H % sum <= max_1)
        count = ((H / sum) * 2) + 1;
    else                                                // H % sum > max_1
        count = ((H / sum) * 2) + 2;

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        ll N, H;
        cin >> N >> H;

        vector<ll> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N, H);
    }
    
    return 0;
}