// getshorty (https://open.kattis.com/problems/getshorty)
 
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <iomanip>
 
using namespace std;
 
// Time: O(ElogV)
// Space: O(V)
 
using edge_t = tuple<int,int,double>;
using queue_state_t = pair<double,int>;
using graph_edge_t = pair<int,double>;
using graph_t = vector<vector<graph_edge_t>>;

void findShortestPath(graph_t& adj_list, int src, int intersec_cnt, vector<double>& dist) {
    vector<int> vis(intersec_cnt+1, 0);

    auto cmp = [&](const auto& s1, const auto& s2) {
        return s1.first < s2.first;
    };
    priority_queue<queue_state_t, vector<queue_state_t>, decltype(cmp)> pq(cmp);
    dist[src] = 1.0;
    pq.push({ dist[src], src });

    while (!pq.empty()) {
        auto [ _, curr ] = pq.top();
        pq.pop();

        if (vis[curr] != 0)
            continue;

        vis[curr] = 1;
        
        for (auto& [next, fac] : adj_list[curr]) {
            if (dist[next] < dist[curr] * fac) {
                dist[next] = dist[curr] * fac;
                pq.push({ dist[next], next });
            }
        }

        vis[curr] = 2;
    }
}

void solve(int intersec_cnt, vector<edge_t>& corridors, int corridor_cnt) {
    graph_t adj_list(intersec_cnt, vector<graph_edge_t>());
    for (auto& [from, to, fac] : corridors) {
        adj_list[from].push_back({ to, fac });
        adj_list[to].push_back({ from, fac });    
    }

    vector<double> dist(intersec_cnt+1, 0.0);
    findShortestPath(adj_list, 0, intersec_cnt, dist);

    cout << fixed << setprecision(4) << dist[intersec_cnt-1] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int intersec_cnt, corridor_cnt;
    cin >> intersec_cnt >> corridor_cnt;
    
    while (intersec_cnt > 0 && corridor_cnt > 0) {
        int u, v;
        double fac;
        vector<edge_t> corridors(corridor_cnt);
        for (int i = 0; i < corridor_cnt; i++) {
            cin >> u >> v >> fac;
            corridors[i] = { u, v, fac };
        }

        solve(intersec_cnt, corridors, corridor_cnt);

        cin >> intersec_cnt >> corridor_cnt;
    }
    
    return 0;
}