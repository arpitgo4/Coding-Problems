// Air Conditioners (https://codeforces.com/problemset/problem/1547/E)
 
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>

using namespace std;
 
// Time: O(N)
// Space: O(N)

#define INF LLONG_MAX

typedef long long ll;

void solve3(vector<int>& pos, vector<ll>& temp, int K, int N) {
    vector<ll> L(N, INF), R(N, INF);
    for (int i = 0; i < K; i++)
        L[pos[i]-1] = R[pos[i]-1] = temp[i];

    for (int i = N-2; i >= 0; i--) {
        if (L[i+1] != INF)
            L[i] = min(L[i], L[i+1]+1);
    }

    for (int i = 1; i < N; i++) {
        if (R[i-1] != INF)
            R[i] = min(R[i], R[i-1]+1);
    }

    for (int i = 0; i < N; i++)
        cout << (min(L[i], R[i])) << " ";
    cout << endl;
}

// Time: O(N * K)
// Space: O(N)
// BFS based approach
// TLE (more efficient than brute-force below, but still TLE's after 6 more test cases)
void solve2(vector<int>& pos, vector<ll>& temp, int K, int N) {
    vector<ll> res(N, INF);

    queue<pair<int,ll>> q;
    for (int i = 0; i < K ; i++) {
        q.push({ pos[i]-1, temp[i] });
        res[pos[i]-1] = temp[i];
    }

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        int u = p.first;
        ll temp_u = p.second;

        int l_idx = u-1;
        if (l_idx >= 0 && res[l_idx] > temp_u+1) {
            res[l_idx] = temp_u+1;
            q.push({ l_idx, res[l_idx] });
        }

        int r_idx = u+1;
        if (r_idx < N && res[r_idx] > temp_u+1) {
            res[r_idx] = temp_u+1;
            q.push({ r_idx, res[r_idx] });
        }
    }

    for (ll t : res)
        cout << t << " ";
    cout << endl;
}

// Time: O(N * K)
// Space: O(1)
// TLE
void solve(vector<int>& pos, vector<ll>& temp, int K, int N) {   
    vector<ll> res(N, INF); 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            res[i] = min(res[i], temp[j] + abs((pos[j]-1) - i));
        }
    }

    for (ll t : res)
        cout << t << " ";
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    int N, K;
    while (T--) {
        cin >> N >> K;

        vector<int> pos(K);
        for (int i = 0; i < K; i++)
            cin >> pos[i];

        vector<ll> temp(K);
        for (int i = 0; i < K; i++)
            cin >> temp[i];

        // solve(pos, temp, K, N);
        // solve2(pos, temp, K, N);
        solve3(pos, temp, K, N);
    }
    
    return 0;
}