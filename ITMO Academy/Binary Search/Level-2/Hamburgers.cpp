// Hamburgers (https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H)
 
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
 
using namespace std;

// Time: O(|S| * log(LLONG_MAX))
// Space: O(1)

#define INF LLONG_MAX

typedef long long ll;
 
bool can_make(vector<ll>& table, ll count, string& S, ll nb, ll ns, ll nc, 
                                                    ll pb, ll ps, ll pc, ll money) {
    
    ll rb = (table['B'-'A'] * count) - nb;
    ll rs = (table['S'-'A'] * count) - ns;
    ll rc = (table['C'-'A'] * count) - nc;

    ll r_money = 0;
    if (rb > 0)
        r_money += rb * pb;
    if (rs > 0)
        r_money += rs * ps;
    if (rc > 0)
        r_money += rc * pc;

    return r_money <= money;
}

void solve(string& S, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll money) {
    vector<ll> table(26, 0);
    for (char c : S)
        table[c-'A']++;

    ll l = 0, h = money + 1000;
    while (l <= h) {
        ll m = (h-l)/2 + l;
        if (can_make(table, m, S, nb, ns, nc, pb, ps, pc, money))
            l = m+1;
        else h = m-1;
    }

    cout << h << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;

    ll nb, ns, nc;
    cin >> nb >> ns >> nc;

    ll pb, ps, pc;
    cin >> pb >> ps >> pc;

    ll money;
    cin >> money;

    solve(S, nb, ns, nc, pb, ps, pc, money);
    
    return 0;
}