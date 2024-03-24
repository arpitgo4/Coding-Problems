// Arbitrage (https://www.spoj.com/problems/ARBITRAG/)
 
#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
// Time: O(V * E)
// Space: O(V)

typedef tuple<string,string,double> edge;
 
unordered_map<string,double> dist;

bool bellman_ford_sssp(vector<edge>& edges, int E, int V) {
    string c1, c2; double rate;
    bool any = false;
    for (int i = 0; i < V; i++) {
        any = false;
        for (edge& e : edges) {
            tie (c1, c2, rate) = e;
            if (dist[c2] < (dist[c1] * rate)) {
                dist[c2] = dist[c1] * rate;
                any = true;
            }
        }
    }

    return any;
}

bool solve(vector<string>& C, int V, vector<edge>& edges, int E) {
    dist.clear();
    for (string& c : C)
        dist[c] = 1;

    return bellman_ford_sssp(edges, E, V);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, idx = 1;
    cin >> V;
    while (V != 0) {
        vector<string> C(V);
        for (int i = 0; i < V; i++)
            cin >> C[i];

        int E;
        cin >> E;

        string c1, c2;
        double rate;
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> c1 >> rate >> c2;
            edges[i] = { c1, c2, rate };
        }

        bool arbitrag_possible = solve(C, V, edges, E);
        cout << "Case " << idx++ << ": " << (arbitrag_possible ? "Yes" : "No") << endl;

        cin >> V;
    }
    
    return 0;
}