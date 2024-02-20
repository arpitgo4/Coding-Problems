// Dragons (https://codeforces.com/problemset/problem/230/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

// Time: O(NlogN)
// Space: O(1)
 
typedef long long ll;

void solve(ll S, vector<pair<ll,ll>>& dragons, int N) {
    sort(dragons.begin(), dragons.end());

    for (int i = 0; i < N; i++) {
        pair<ll,ll>& p = dragons[i];
        if (S <= p.first) {
            cout << "NO";
            return;
        }

        S += p.second;
    }

    cout << "YES";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; ll S;
    cin >> S >> N;

    ll x, y;
    vector<pair<ll,ll>> dragons(N);
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        dragons[i] = { x, y };
    }

    solve(S, dragons, N);
    
    return 0;
}