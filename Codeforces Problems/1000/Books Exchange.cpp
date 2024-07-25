// Books Exchange (https://codeforces.com/problemset/problem/1249/B1)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
/**
 * find all cycles length
 * 
 * for any node, whatever is the length of cycle is
 * that is the answer for it.
 * 
 * for node's pointing to themselves, answer is 1.
 * i.e. number of edges in the cycle.
 * 
 * Thought: In iteration, we have to take decision or solve the problem
 *          then and there.
 *          In recursion, we are free to take decision or solve the problem
 *          after exploring all the subproblems and having a wider look at
 *          all the problem space.
 */

vector<int> vis, len;

int dfs(int u, int depth, vector<int>& P) {
    if (vis[u] == 1)
        return depth;

    vis[u] = 1;
    int v = P[u];
    return len[u] = dfs(v, depth+1, P);
}

void solve(vector<int>& P, int N) {
    vis.assign(N+1, 0);
    len.assign(N+1, 0);

    for (int i = 1; i <= N; i++)
        dfs(i, 0, P);

    for (int i = 1; i <= N; i++)
        cout << len[i] << " ";
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> P(N+1);
        for (int i = 1; i <= N; i++)
            cin >> P[i];

        solve(P, N);
    }
    
    return 0;
}