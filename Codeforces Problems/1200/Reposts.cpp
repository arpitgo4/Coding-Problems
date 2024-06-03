// Reposts (https://codeforces.com/problemset/problem/522/A)
 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <algorithm>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
  
typedef pair<int,int> edge;

vector<vector<int>> T;
unordered_map<string,int> uMap;

int dfs(int u, int p) {
    int max_dist = 1;
    for (int v : T[u]) {
        if (v != p) {
            max_dist = max(max_dist, 1 + dfs(v, u));
        }
    }

    return max_dist;
}

void solve(vector<edge>& edges, int V) {
    T.assign(V+1, vector<int>());
    for (edge& e : edges) {
        int u = e.first, v = e.second;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    int max_repost = dfs(1, -1);
    cout << max_repost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int counter = 0;
    string name1, name2, repost;

    vector<edge> edges(N);
    for (int i = 0; i < N; i++) {
        cin >> name1 >> repost >> name2;
        transform(name1.begin(), name1.end(), name1.begin(), ::tolower); 
        transform(name2.begin(), name2.end(), name2.begin(), ::tolower); 
        if (uMap.find(name2) == uMap.end())
            uMap[name2] = ++counter;
        if (uMap.find(name1) == uMap.end())
            uMap[name1] = ++counter;
        
        edges[i] = { uMap[name1], uMap[name2] };
    }

    solve(edges, counter);
    
    return 0;
}