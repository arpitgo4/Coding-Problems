// visualgo (https://open.kattis.com/problems/visualgo)
 
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <cmath>
 
using namespace std;
 
// Time: O(ElogV + (V + E))
// Space: O(V)
 
const int INF = INT_MAX;

using ll_t = long long;
using edge_t = tuple<int,int,ll_t>;
using graph_edge_t = pair<int,ll_t>;
using graph_t = vector<vector<graph_edge_t>>;
using queue_state_t = pair<ll_t,int>;
using dag_t = vector<vector<int>>;

int countPathsInDAG(dag_t& adj_list, int src, int dest, vector<int>& vis, vector<int>& dp) {
    if (src == dest)
        return 1;

    vis[src] = 1;

    int count = 0;
    for (int next : adj_list[src]) {
        if (vis[next] == 0) {
            count += countPathsInDAG(adj_list, next, dest, vis, dp);
        } else {                                                        // back-edge or cross-edge
            count += dp[next];
        }
    }

    vis[src] = 2;

    return dp[src] = count;
}

void buildShortestPathDAG(
    graph_t& adj_list, 
    int src, 
    int dest, 
    int vertex_cnt,
    vector<ll_t>& dist,
    dag_t& parent
) {
    vector<int> vis(vertex_cnt+1, 0);

    auto cmp = [&](const auto& s1, const auto& s2) {
        return s1.first > s2.first;
    };
    priority_queue<queue_state_t, vector<queue_state_t>, decltype(cmp)> pq(cmp);

    dist[src] = 0;
    pq.push({ dist[src], src });

    while (!pq.empty()) {
        auto [ _, curr ] = pq.top();
        pq.pop();

        if (vis[curr] != 0)
            continue;

        vis[curr] = 1;
        for (auto& [next, weight] : adj_list[curr]) {
            if (dist[next] > dist[curr] + weight) {
                dist[next] = dist[curr] + weight;
                pq.push({ dist[next], next });

                parent[next].clear();
                parent[next].push_back(curr);
            }
            else if (dist[next] == dist[curr] + weight) {
                parent[next].push_back(curr);
            }
        }

        vis[curr] = 2;
    }
}

void solve(int vertex_cnt, vector<edge_t>& edges, int edge_cnt, int src, int dest) {
    graph_t adj_list(vertex_cnt+1, vector<graph_edge_t>());
    for (auto& [from, to, weight] : edges) {
        adj_list[from].push_back({ to, weight });
    }

    vector<ll_t> dist(vertex_cnt+1, INF);
    dag_t parent(vertex_cnt+1, vector<int>());

    buildShortestPathDAG(adj_list, src, dest, vertex_cnt, dist, parent);

    vector<int> vis(vertex_cnt+1, 0);
    vector<int> dp(vertex_cnt+1, -1);
    int path_cnt = countPathsInDAG(parent, dest, src, vis, dp);

    cout << path_cnt << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int vertex_cnt, edge_cnt;
    cin >> vertex_cnt >> edge_cnt;
    
    int u, v;
    ll_t w;
    vector<edge_t> edges(edge_cnt);
    for (int i = 0; i < edge_cnt; i++) {
        cin >> u >> v >> w;
        edges[i] = { u, v, w };
    }

    int src, dest;
    cin >> src >> dest;

    solve(vertex_cnt, edges, edge_cnt, src, dest);
    
    return 0;
}