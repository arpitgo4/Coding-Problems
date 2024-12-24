// runningmom (https://open.kattis.com/problems/runningmom)
 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <climits>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)

#define INF INT_MAX

unordered_map<string,int> uMap;
vector<string> words;

vector<vector<int>> G;
vector<int> vis, low_link;

void dfs(int u) {
    vis[u] = 1;

    for (int v : G[u]) {
        if (vis[v] == 0) {                                          // tree-edge
            dfs(v);
            low_link[u] = min(low_link[u], low_link[v]);
        } else if (vis[v] == 1) {                                   // back-edge or bidirectional-edge
            low_link[u] = v;
        } else if (vis[v] == 2) {                                   // cross-edge
            low_link[u] = min(low_link[u], low_link[v]);
        }
    }

    vis[u] = 2;
}

void build_graph(vector<string>& A) {
    int N = A.size();

    G.assign(N+1, vector<int>());
    vis.assign(N+1, 0);
    low_link.assign(N+1, INF);

    for (int i = 0; i < N; i+=2) {
        string& w1 = A[i], w2 = A[i+1];
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int E;
    cin >> E;
    
    string word;
    vector<string> cities;
    for (int i = 0; i < E; i++) {
        cin >> word;
        cities.push_back(word);
        cin >> word;
        cities.push_back(word);
    }
        
    build_graph(cities);

    int V = G.size();
    for (int u = 0; u < V; u++) {
        if (vis[u] == 0)
            dfs(u);
    }

    cin.ignore();
    while(getline(cin, word)) {
        int u = uMap[word];
        cout << word << " " << (low_link[u] == INF ? "trapped" : "safe") << endl;
    }

    return 0;
}