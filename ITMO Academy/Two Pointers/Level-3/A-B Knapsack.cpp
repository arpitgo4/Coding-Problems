// A-B Knapsack (https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/H)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O()
// Space: O()
 
typedef long long ll;
 
vector<vector<int>> dp;

ll dfs(int i, int j, vector<ll>& A, int N, vector<ll>& B, int M, ll S, ll W_A, ll W_B) {
    if (i == N && j == M)
        return 0;
    
    
}

void solve(vector<ll>& A, int N, vector<ll>& B, int M, ll S, ll W_A, ll W_B) {
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; ll S, W_A, W_B;
    cin >> N >> M >> S >> W_A >> W_B;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<ll> B(M);
    for (int i = 0; i < M; i++)
        cin >> B[i];

    solve(A, N, B, M, S, W_A, W_B);
    
    return 0;
}