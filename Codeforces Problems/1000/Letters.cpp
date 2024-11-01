// Letters (https://codeforces.com/problemset/problem/978/C)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(N + MlogN)
// Space: O(N)
 
typedef long long ll;

vector<ll> pref;

pair<ll,ll> query(ll q, int N) {
    auto itr = lower_bound(pref.begin(), pref.end(), q);
    int i = itr - pref.begin();

    ll j;
    if (i == 0) {
        j = q;
    } else {
        j = q - pref[i-1];
    }

    return { i+1, j };
}

void solve(vector<ll>& A, int N) {
    pref.assign(N, 0);
    pref[0] = A[0];
    for (int i = 1; i < N; i++)
        pref[i] = pref[i-1] + A[i];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);

    ll q;
    for (int i = 0; i < M; i++) {
        cin >> q;

        auto [ dorm, room ] = query(q, N);
        cout << dorm << " " << room << endl;
    }
    
    return 0;
}