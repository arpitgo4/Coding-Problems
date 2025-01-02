// UVa 00336 - A Node Too Far (https://onlinejudge.org/external/3/336.pdf)
 
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
 
using namespace std;
 
// Time: O(Q * (V + E))
// Space: O(V + E)

typedef pair<int,int> edge;
typedef pair<int,int> state;

int tot_cnt;
unordered_map<int, vector<int>> G;
unordered_map<int,int> vis;

int bfs(int src, int ttl) {
    vis.clear();

    queue<state> q;
    q.push({ src, ttl });
    vis[src] = 1;

    int cnt = 1;
    while (!q.empty()) {
        auto p = q.front();
        int u = p.first, u_ttl = p.second;
        q.pop();
        
        if (vis[u] == 2)
            continue;

        for (int v : G[u]) {
            if (vis.find(v) == vis.end() && u_ttl-1 >= 0) {
                q.push({ v, u_ttl-1 });
                vis[v] = 1;
                cnt++;
            }
        }

        vis[u] = 2;
    }

    return cnt;
}

void build_graph(vector<edge>& edges, int E) {
    G.clear();

    int u, v;
    for (edge& e : edges) {
        u = e.first; v = e.second;
        if (G.find(u) == G.end()) {
            G.insert({ u, vector<int>() });
        }
        if (G.find(v) == G.end()) {
            G.insert({ v, vector<int>() });
        }

        G[u].push_back(v);
        G[v].push_back(u);
    }

    tot_cnt = G.size();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int idx = 0;
    int E;
    cin >> E;
    
    while (E != 0) {
        int u, v;
        
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            edges[i] = { u, v };
        }
    
        build_graph(edges, E);

        int src, ttl;
        cin >> src >> ttl;

        while (ttl > 0) {
            int cnt = bfs(src, ttl);

            cout << "Case " << (idx+1) << ": " << (tot_cnt-cnt) << " nodes not reachable from node " << src << " with TTL = " << ttl << "." << endl;

            cin >> src >> ttl;
            idx++;
        }

        cin >> E;
    }
    
    return 0;
}