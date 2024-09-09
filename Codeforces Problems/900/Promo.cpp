// Promo (https://codeforces.com/problemset/problem/1697/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN + Q)
// Space: O(N)
 
typedef long long ll;

vector<ll> PF;

ll query(int x, int y, int N) {
    return PF[N-x+y] - PF[N-x];
}

void build_prefix_sum(vector<ll>& A, int N) {
    sort(A.begin(), A.end());

    PF.assign(N+1, 0);
    for (int i = 1; i <= N; i++)
        PF[i] = PF[i-1] + A[i-1];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    build_prefix_sum(A, N);

    int x, y;
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        ll val = query(x, y, N);
        cout << val << endl;
    }
    
    return 0;
}