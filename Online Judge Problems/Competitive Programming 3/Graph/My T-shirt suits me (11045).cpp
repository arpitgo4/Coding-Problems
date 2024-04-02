// My T-shirt suits me (11045)
 
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
 
using namespace std;
 
// Time: O(V * E^2)
// Space: O(E)
 
/**
3
18 6 
L XL 
XL L 
XXL XL 
S XS 
M S 
M L
6 4
S XL
L S
L XL 
L XL 
6 1 
L M
*/

#define INF INT_MAX

typedef pair<int,int> edge;
typedef pair<int,int> state;

vector<vector<int>> G, C;
vector<int> vis, P;

const int SRC = 1;
const int BASE_V1 = 2;
const int BASE_V2 = 50;
const int SINK = 100;
const int V = 100;
unordered_map<string,int> size_map{
    { "XS", BASE_V2+1 },
    { "S", BASE_V2+2 },
    { "M", BASE_V2+3 },
    { "L", BASE_V2+4 },
    { "XL", BASE_V2+5 },
    { "XXL", BASE_V2+6 },
};
 
int bfs() {
    vis.assign(V+1, 0);
    P.assign(V+1, -1);

    queue<state> q({{ SRC, INF }});
    vis[SRC] = 1;

    while (!q.empty()) {
        state p = q.front();
        q.pop();

        int u = p.first, flow = p.second;
        if (u == SINK)
            return flow;

        for (int v : G[u]) {
            if (vis[v] == 0 && C[u][v] > 0) {
                vis[v] = 1;
                P[v] = u;
                q.push({ v, min(flow, C[u][v]) });
            }
        }
    }

    return 0;
}

int maximum_flow() {
    int flow = 0, max_flow = 0;
    while ((flow = bfs()) > 0) {
        max_flow += flow;
        
        int curr = SINK;
        while (curr != SRC) {
            int prev = P[curr];
            C[prev][curr] -= flow;
            C[curr][prev] += flow;
            curr = prev;
        }
    }

    return max_flow;
} 

void build_graph(vector<edge>& edges, int N, int M) {
    G.assign(V+1, vector<int>());
    C.assign(V+1, vector<int>(V+1, 0));

    // C[src][vol] = 1
    for (int i = BASE_V1; i < BASE_V1 + M; i++) {
        G[SRC].push_back(i);
        G[i].push_back(SRC);
        C[SRC][i] = 1;
    }

    for (edge& e : edges) {
        int u = e.first, v = e.second;
        G[u].push_back(v);
        G[v].push_back(u);
        C[u][v] = 1;
    }

    // C[shirt][sink] = N/6
    for (auto& p : size_map) {
        G[p.second].push_back(SINK);
        G[SINK].push_back(p.second);
        C[p.second][SINK] = N/6;
    }
}

void solve(vector<edge>& edges, int N, int M) {
    build_graph(edges, N, M);

    int max_flow = maximum_flow();
    cout << (max_flow == M ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        string s1, s2;
        vector<edge> edges(M*2);
        int volunteer = BASE_V1;
        for (int i = 0; i < M*2; i+=2) {
            cin >> s1 >> s2;
            edges[i] = { volunteer, size_map[s1] };
            edges[i+1] = { volunteer, size_map[s2] };
            volunteer++;
        }

        solve(edges, N, M);
    }
    
    return 0;
}