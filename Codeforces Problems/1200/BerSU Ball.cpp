// BerSU Ball (https://codeforces.com/problemset/problem/489/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
// Time: O(N * M)
// Space: O(1)
 
/**
 * Can be solved with max-flow algorithm for 
 * maximal matching in a bipartite graph
 * 
 * Create a bipartite graph with edges only 
 * between a boy and girl where the skill diff [-1, 0, +1]
 * 
 * Run the max flow algorithm and we can get the max pair
 * we can make.
 * 
 * Time: O(V * E^2)
 * Space: O(V^2)
 * 
 * Greedy approach,
 * Sort boys and girls by skill
 * Match the boy with lower skill with girl with lower skill
 * 
 * Time: O(NlogN + MlogM)
 * Space: O(1)
 */

void solve(vector<int>& B, int N, vector<int>& G, int M) {
    sort(B.begin(), B.end());
    sort(G.begin(), G.end());

    int count = 0, j = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (abs(B[i] - G[j]) <= 1) {
                G[j] = 1000;
                count++;
                break;
            }
        }    
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> B(N);
    for (int i = 0; i < N; i++)
        cin >> B[i];

    int M;
    cin >> M;

    vector<int> G(M);
    for (int i = 0; i < M; i++)
        cin >> G[i];

    solve(B, N, G, M);
    
    return 0;
}