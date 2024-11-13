// Kuriyama Mirai's Stones (https://codeforces.com/problemset/problem/433/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
typedef long long ll;

vector<ll> pref_sum, ord_pref_sum;

ll query_1(int l, int r) {
    if (l == 0)
        return pref_sum[r];
    return pref_sum[r] - pref_sum[l-1];
}

ll query_2(int l, int r) {
    if (l == 0)
        return ord_pref_sum[r];
    return ord_pref_sum[r] - ord_pref_sum[l-1];
}

void solve(vector<ll>& A, int N) {
    pref_sum.assign(N, 0);
    pref_sum[0] = A[0];
    for (int i = 1; i < N; i++)
        pref_sum[i] = pref_sum[i-1] + A[i];

    sort(A.begin(), A.end());
    ord_pref_sum.assign(N, 0);
    ord_pref_sum[0] = A[0];
    for (int i = 1; i < N; i++)
        ord_pref_sum[i] = ord_pref_sum[i-1] + A[i];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);

    int Q;
    cin >> Q;

    int type, l, r;
    for (int i = 0; i < Q; i++) {
        cin >> type >> l >> r;
        if (type == 1) {
            cout << query_1(l-1, r-1) << endl;
        } else {
            cout << query_2(l-1, r-1) << endl;
        }
    }
    
    return 0;
}