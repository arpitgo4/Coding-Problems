// Also Try Minecraft (https://codeforces.com/problemset/problem/1709/B)
 
#include <iostream>
#include <vector>
 
using namespace std;

// Time: O(N)
// Space: O(N)

/**
 * Mathematical function to get return values within certain bounds,
 * max<?> and min<?>
 * 
 * To get values within let's say, 0 and all +ve, max(0, whatever_num)
 * To get values within let's say, -ve and 0, min(whatever_num, 0)
 * 
 * max and min functions are template based.
 * max<long long int>, min<long>
 */

typedef long long ll;

vector<ll> dp_L, dp_R;

ll query(int s, int t) {
    if (s <= t)
        return dp_R[s]-dp_R[t];
    else return dp_L[s]-dp_L[t];
}

ll dfs2(int i, vector<ll>& A, int N) {
    if (i == 0)
        return 0;
    return dp_L[i] = dfs2(i-1, A, N) + max<ll>(0, A[i]-A[i-1]);
}

ll dfs1(int i, vector<ll>& A, int N) {
    if (i == N-1)
        return 0;
    return dp_R[i] = dfs1(i+1, A, N) + max<ll>(0, A[i]-A[i+1]);
}

void solve(vector<ll>& A, int N) {
    dp_L.assign(N, 0);
    dp_R.assign(N, 0);

    dfs1(0, A, N);
    dfs2(N-1, A, N);
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

    int s, t;
    for (int i = 0; i < M; i++) {
        cin >> s >> t;
        cout << query(s-1, t-1) << endl;
    }
    
    return 0;
}