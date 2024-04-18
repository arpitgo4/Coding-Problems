// 2D Traveling (https://codeforces.com/problemset/problem/1869/B)
 
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <unordered_map>
 
using namespace std;
 
// Time: O(N^2 * logN)
// Space: O(N)

// Shortest-path in a weighted graph,
// Dijkstra's SSSP Algorithm
// Above approach gives TLE, 
// Tutorial: https://codeforces.com/blog/entry/116642
 
#define INF LLONG_MAX
 
typedef long long ll;
typedef pair<ll,ll> coordinate;
typedef pair<int,ll> graph_edge;
typedef pair<ll,int> state;
 
vector<ll> dist;
vector<int> vis;

int node_id = 1;
unordered_map<int,coordinate> V;

ll cost(int node_1, int node_2, int K) {
    if (node_1 <= K && node_2 <= K)
        return 0;

    coordinate& c1 = V[node_1];
    coordinate& c2 = V[node_2];
    return abs(c1.first - c2.first) + abs(c1.second - c2.second);
}

void dijkstra(int src, int dest, int N, int K) {
    auto comp = [&](const state& s1, const state& s2) {
        return s1.first > s2.first;
    };
    priority_queue<state, vector<state>, decltype(comp)> pq(comp);           // min-heap
    dist[src] = 0;
    pq.push({ dist[src], src });

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        int u = p.second;
        if (vis[u] != 0)
            continue;
        vis[u] = 1;

        if (u == dest)
            return;

        for (int v = 1; v <= N; v++) {
            ll w = cost(u, v, K);
            if (dist[v] > dist[u] + w) {
                dist[v] =  dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
}

void solve(int N, int K, int src, int dest) {
    dist.assign(N+1, INF);
    vis.assign(N+1, 0);

    dijkstra(src, dest, N, K);

    cout << dist[dest] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, K, src, dest;
        cin >> N >> K >> src >> dest;

        node_id = 1;
        V.clear();

        ll x, y;
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            V.insert({ node_id, { x, y } });
            node_id++;
        }

        solve(N, K, src, dest);
    }   
    
    return 0;
}