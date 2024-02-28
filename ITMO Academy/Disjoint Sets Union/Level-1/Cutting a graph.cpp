// Cutting a graph (https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D)
 
#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>
 
using namespace std;
 
// Time: O(log*(V))
// Space: O(V)

// NOTE: input is problematic and not formatted correctly

vector<int> P, S;

void init_dsu(int V) {
    P.assign(V+1, 0);
    S.assign(V+1, 1);
    for (int i = 0; i < V+1; i++)
        P[i] = i;
}

int root(int x) {
    if (P[x] != x)
        P[x] = root(P[x]);

    return P[x];
}

void union_set(int x, int y) {
    int root_x = root(x);
    int root_y = root(y);
    if (root_x == root_y)
        return;

    if (S[root_x] > S[root_y]) {
        P[root_y] = P[root_x];
        S[root_x] += S[root_y];
        S[root_y] = -1;
    } else {
        P[root_x] = P[root_y];
        S[root_y] += S[root_x];
        S[root_x] = -1;
    }
}

void solve(int V, int E, vector<vector<string>>& queries) {
    init_dsu(V);

    int N = queries.size();

    string type;
    int u, v;
    vector<int> res(N);
    for (int i = N-1; i >= 0; i--) {
        cout << queries[i][0] << queries[i][1] << " " << queries[i][2] << endl;
        type = queries[i][0];
        u = stoi(queries[i][1]);
        v = stoi(queries[i][2]);
        if (type == "ask") {
            if (root(u) == root(v))
                res[i] = 1;
            else res[i] = 0;
        }
        else 
            union_set(u, v);
    }

    for (int r : res)
        cout << (r == 1 ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E, Q;
    cin >> V >> E >> Q;

    int u, v;
    vector<pair<int,int>> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        edges[i] = { u, v };
    }

    string line;
    vector<string> queries(Q); 
    for (int i = 0; i < Q; i++) {
        cin >> line;
        queries[i] = line;

        // string s;
        // stringstream ss(line);
        // vector<string> v;
        // while (getline(ss, s, ' ')) {
        //     v.push_back(s);
        // }
        // queries.push_back(v);
    }

    for (string& s : queries)
        cout << s << endl;

    // solve(V, E, queries);
    
    return 0;
}