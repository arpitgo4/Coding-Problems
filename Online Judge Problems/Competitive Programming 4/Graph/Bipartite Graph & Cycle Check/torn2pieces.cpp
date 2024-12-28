// torn2pieces (https://open.kattis.com/problems/torn2pieces)
 
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)
 
typedef pair<int,int> edge;

const int MAX_N = 32 * 32;

vector<vector<int>> G;
vector<int> vis, P;

unordered_map<string,int> uMap;
vector<string> words;

void dfs(int u) {
    vis[u] = 1;

    // if we get a back/bidirectional edge or cross edge, ignore it
    for (int v : G[u]) {
        if (vis[v] == 0) {
            dfs(v);
            P[v] = u;                                                   // DFS spanning tree
        }
    }

    vis[u] = 2;
}

void solve(string& line) {
    stringstream ss(line);

    string s_src, s_dest;
    ss >> s_src >> s_dest;

    int src = uMap[s_src];
    dfs(src);

    int curr = uMap[s_dest];
    vector<int> trip;
    while (curr != -1) {
        trip.push_back(curr);
        curr = P[curr];
    }

    if (trip.size() == 1) {
        cout << "no route found" << endl;
    } else {
        reverse(trip.begin(), trip.end());
        for (int u : trip) {
            cout << words[u] << " ";
        }
        cout << endl;
    }
}
 
void build_graph(vector<string>& lines, int N) {
    G.assign(MAX_N+1, vector<int>());
    vis.assign(MAX_N+1, 0);
    P.assign(MAX_N+1, -1);
    uMap.clear();
    words.clear();

    for (string& line : lines) {
        stringstream ss(line);

        string w1, w2;
        ss >> w1;
        if (uMap.find(w1) == uMap.end()) {
            words.push_back(w1);
            uMap.insert({ w1, words.size()-1 });
        }

        while (ss >> w2) {
            if (uMap.find(w2) == uMap.end()) {
                words.push_back(w2);
                uMap.insert({ w2, words.size()-1 });
            }

            G[uMap[w1]].push_back(uMap[w2]);
            G[uMap[w2]].push_back(uMap[w1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    cin.ignore();

    string line;
    vector<string> lines(N);
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        lines[i] = line;
    }

    build_graph(lines, N);

    getline(cin, line);
    
    solve(line);
    
    return 0;
}