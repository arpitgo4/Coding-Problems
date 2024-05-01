// Hoax or what (11136)
 
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)

typedef long long ll;

void solve(vector<vector<ll>>& bills, int N) {
    multiset<ll> om_set;

    ll cost = 0;
    for (int i = 0; i < N; i++) {
        for (ll b : bills[i])
            om_set.insert(b);

        auto hi = prev(om_set.end());
        auto lo = om_set.begin();
        cost += (*hi) - (*lo);

        om_set.erase(hi);
        om_set.erase(lo);
    }

    cout << cost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    while (N != 0) {
        vector<vector<ll>> bills(N, vector<ll>());
        for (int i = 0; i < N; i++) {
            int K;
            cin >> K;

            bills[i].resize(K);
            for (int j = 0; j < K; j++)
                cin >> bills[i][j];
        }

        solve(bills, N);

        cin >> N;
    }   
    
    return 0;
}