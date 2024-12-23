// builddeps (https://open.kattis.com/problems/builddeps)
 
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)

unordered_map<string,int> uMap;
vector<string> words;

vector<vector<int>> G;
vector<int> vis, topo;

void dfs(int u) {
    vis[u] = 1;

    for (int v : G[u]) {
        if (vis[v] == 0) {
            dfs(v);
        }
    }

    vis[u] = 2;
    topo.push_back(u);
}

void build_graph(vector<string>& lines, int N) {
    G.assign(N * 5, vector<int>());
    vis.assign(N * 5, 0);

    for (string& line : lines) {
        string main_file = line.substr(0, line.find(':'));
        if (uMap.find(main_file) == uMap.end()) {
            words.push_back(main_file);
            uMap.insert({ main_file, words.size()-1 });
        }

        size_t i = line.find(':');
        if (i == string::npos) 
            continue;

        string deps = line.substr(i+1);
        stringstream ss(deps);

        string dep;
        while (ss >> dep) {
            if (uMap.find(dep) == uMap.end()) {
                words.push_back(dep);
                uMap.insert({ dep, words.size()-1 });
            }

            G[uMap[dep]].push_back(uMap[main_file]);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    cin.ignore();

    vector<string> lines(N);
    for (int i = 0; i < N; i++)
        getline(cin, lines[i]);

    build_graph(lines, N);

    string updated_file;
    cin >> updated_file;

    dfs(uMap[updated_file]);

    reverse(topo.begin(), topo.end());
    for (int u : topo)
        cout << words[u] << endl;

    return 0;
}