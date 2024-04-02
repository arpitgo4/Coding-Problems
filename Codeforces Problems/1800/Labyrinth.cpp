// Labyrinth (https://codeforces.com/problemset/problem/1063/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O()
// Space: O()
 
#define INF LLONG_MAX
 
typedef long long ll;

vector<vector<int>> G;
 
void solve(int N, int M, int s_i, int s_j, int max_l, int max_r) {
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    int s_i, s_j;
    cin >> s_i >> s_j;

    int max_l, max_r;
    cin >> max_l >> max_r;

    G.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)

    solve(N, M, s_i, s_j, max_l, max_r);
    
    return 0;
}