// Make It One (https://codeforces.com/problemset/problem/1043/F)
 
#include <iostream>
#include <vector>
#include <bitset>
#include <numeric>
 
using namespace std;
 
// Time: O()
// Space: O()
 
const int MAX_N = 3e5;

#define INF LLONG_MAX

vector<vector<bitset<MAX_N+1>>> dp;

int dfs(int i, bitset<MAX_N+1> mask, vector<int>& A, int N) {
    if (i == N)
        return mask.count();
    
    
}

void solve(vector<int>& A, int N) {
    dp.assign(N, vector<bitset<MAX_N+1>>());

    bitset<MAX_N+1> mask;
    int min_count = dfs(0, mask, A, N);

    cout << min_count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);
    
    return 0;
}