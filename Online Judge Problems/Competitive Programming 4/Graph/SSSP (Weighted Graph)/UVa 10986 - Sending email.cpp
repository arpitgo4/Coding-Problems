// UVa 10986 - Sending email (https://onlinejudge.org/external/109/10986.pdf)
 
#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
#include <queue>
 
using namespace std;
 
// Time: O(ElogV)
// Space: O(V)
 
#define INF LLONG_MAX

typedef long long LLong;
typedef tuple<int,int,LLong> Edge;
typedef pair<int,LLong> GraphEdge;
typedef vector<vector<GraphEdge>> Graph;
typedef pair<LLong,int> QueueState;

void dijkstra(Graph& adj_list, int src, int dest, vector<LLong>& dist, vector<int>& vis) {
    auto cmp = [&](const QueueState& s1, const QueueState& s2) {
        return s1.first > s2.first;
    };
    priority_queue<QueueState, vector<QueueState>, decltype(cmp)> pq(cmp);
    dist[src] = 0;
    pq.push({ dist[src], src });

    while (!pq.empty()) {
        QueueState state = pq.top();
        int curr = state.second;
        pq.pop();

        if (vis[curr] == 1)
            continue;

        for (GraphEdge& edge : adj_list[curr]) {
            int next = edge.first;
            LLong weight = edge.second;
            if (dist[next] > dist[curr] + weight) {
                dist[next] = dist[curr] + weight;
                pq.push({ dist[next], next });
            }
        }

        vis[curr] = 1;
    }
}

void solve(int test_id, vector<Edge>& conns, int conn_cnt, int server_cnt, int src, int dest) {
    Graph adj_list(server_cnt+1, vector<GraphEdge>());

    int u, v; LLong w;
    for (Edge& edge : conns) {
        tie(u, v, w) = edge;
        adj_list[u].push_back({ v, w });
        adj_list[v].push_back({ u, w });
    }

    vector<int> vis(server_cnt+1, 0);
    vector<LLong> dist(server_cnt+1, INF);

    dijkstra(adj_list, src, dest, dist, vis);

    cout << "Case #" << (test_id+1) << ": ";
    if (dist[dest] == INF) {
        cout << "unreachable" << endl;
    } else {
        cout << dist[dest] << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_id = 0;
    int T;
    cin >> T;
    
    while (test_id < T) {
        int server_cnt, conn_cnt, src, dest;
        cin >> server_cnt >> conn_cnt >> src >> dest;
        
        int u, v; LLong w;
        vector<Edge> conns(conn_cnt);
        for (int i = 0; i < conn_cnt; i++) {
            cin >> u >> v >> w;
            conns[i] = { u, v, w };
        }
    
        solve(test_id, conns, conn_cnt, server_cnt, src, dest);
        test_id++;
    }
    
    return 0;
}