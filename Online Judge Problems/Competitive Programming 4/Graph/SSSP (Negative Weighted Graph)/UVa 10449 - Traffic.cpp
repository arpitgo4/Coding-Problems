// UVa 10449 - Traffic (https://onlinejudge.org/external/104/10449.pdf)
 
#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <tuple>
 
using namespace std;
 
// Time: O(V * E)
// Space: O(V)
 
#define INF INT_MAX

typedef pair<int,int> edge;

vector<int> dist;

int cube(int x) {
    return x * x * x;
}

void bellman_ford_sssp(vector<edge>& edges, int E, vector<int>& B, int V) {
    dist.assign(V, INF);
    dist[0] = 0;

    int u, v;
    for (int i = 0; i < V-1; i++) {
        for (edge& edge : edges) {
            tie(u, v) = edge;
            int w = cube(B[v] - B[u]);
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int idx = 0;
    string line;
    
    while (getline(cin, line)) {
        stringstream ss(line);

        int V;
        ss >> V;
        
        vector<int> B(V);
        for (int i = 0; i < V; i++)
            cin >> B[i];

        int E;
        cin >> E;
        
        int u, v;
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            edges[i] = { u-1, v-1 };
        }
    
        bellman_ford_sssp(edges, E, B, V);

        cout << "Set #" << (idx + 1) << endl;

        int Q;
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            cin >> v;
            v--;
            if (dist[v] < 3)
                cout << "?" << endl;
            else cout << dist[v] << endl;
        }

        idx++;
        cin.ignore();
    }
    
    return 0;
}