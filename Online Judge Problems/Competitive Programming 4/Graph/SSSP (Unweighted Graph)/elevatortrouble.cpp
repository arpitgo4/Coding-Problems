// elevatortrouble (https://open.kattis.com/problems/elevatortrouble)
 
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)

#define INF INT_MAX

vector<int> vis, cnt;

void bfs(int V, int src, int dest, int up, int down) {
    vector<int> moves{ up, -down };

    queue<int> q;
    q.push(src);
    vis[src] = 1;
    cnt[src] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (vis[u] == 2)
            continue;

        for (int move : moves) {
            int v = u + move;
            if (v >= 0 && v < V && vis[v] == 0) {
                q.push(v);
                vis[v] = 1;
                cnt[v] = cnt[u] + 1;
            }
        }

        vis[u] = 2;
    }
}

void solve(int V, int src, int dest, int up, int down) {
    vis.assign(V+1, 0);
    cnt.assign(V+1, INF);

    bfs(V, src, dest, up, down);

    if (cnt[dest] == INF)
        cout << "use the stairs" << endl;
    else cout << cnt[dest] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, src, dest, up, down;
    cin >> V >> src >> dest >> up >> down;

    src--;
    dest--;

    solve(V, src, dest, up, down);
    
    return 0;
}