// UVa 00247 - Calling Circles (https://onlinejudge.org/external/2/247.pdf)
 
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <unordered_map>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)

#define INF INT_MAX

typedef pair<string,string> string_edge;

vector<vector<int>> G;
vector<int> vis, low_link, s_time;
vector<bool> on_stk;

stack<int> stk;

int timer;

unordered_map<string,int> uMap;
vector<string> words;

vector<vector<string>> circles;

void dfs(int u) {
    s_time[u] = low_link[u] = timer++;
    stk.push(u);
    on_stk[u] = true;
    vis[u] = 1;

    for (int v : G[u]) {
        if (vis[v] == 0) {
            dfs(v);
            low_link[u] = min(low_link[u], low_link[v]);
        } else if (on_stk[v]) {
            low_link[u] = min(low_link[u], s_time[v]);
        }
    }

    if (s_time[u] == low_link[u]) {
        circles.push_back(vector<string>());

        int v;
        do {
            v = stk.top();
            stk.pop();
            on_stk[v] = false;
            circles.back().push_back(words[v]);
        } while (v != u);
    }

    vis[u] = 2;
}

void build_graph(vector<string_edge>& edges, int E, int V) {
    G.assign(V+1, vector<int>());
    vis.assign(V+1, 0);
    s_time.assign(V+1, -1);
    low_link.assign(V+1, INF);
    on_stk.assign(V+1, false);
    timer = 0;
    uMap.clear();
    words.clear();
    circles.clear();

    for (auto& edge : edges) {
        string& w1 = edge.first, w2 = edge.second;
        if (uMap.find(w1) == uMap.end()) {
            words.push_back(w1);
            uMap.insert({ w1, words.size()-1 });
        }
        if (uMap.find(w2) == uMap.end()) {
            words.push_back(w2);
            uMap.insert({ w2, words.size()-1 });
        }

        G[uMap[w1]].push_back(uMap[w2]);
    }
}

void solve(vector<string_edge>& edges, int E, int V) {
    build_graph(edges, E, V);

    for (int u = 0; u < V; u++) {
        if (vis[u] == 0)
            dfs(u);
    }

    for (auto& circle : circles) {
        int N = circle.size();
        for (int i = 0; i < N; i++) {
            cout << circle[i];
            if (i < N-1)
                cout << ", ";
        }
        cout << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin >> V >> E;
    
    int idx = 0;
    while (V > 0 || E > 0) {
        vector<string_edge> edges(E);

        string u, v;
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            edges[i] = { u, v };
        }

        cout << "Calling circles for data set" << (idx+1) << ":" << endl;

        solve(edges, E, V);

        cout << endl;

        cin >> V >> E;
        idx++;
    }
    
    return 0;
}