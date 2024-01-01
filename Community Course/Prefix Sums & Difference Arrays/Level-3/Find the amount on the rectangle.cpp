// Find the amount on the rectangle (https://codeforces.com/edu/course/3/lesson/10/3/practice/contest/324368/problem/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
// Time: O(N * M)
// Space: O(N * M)

const int MAX_N = 1000 + 1;
vector<vector<ll>> prefix_sum(MAX_N, vector<ll>(MAX_N, 0));

ll query(int i1, int j1, int i2, int j2) {
    return prefix_sum[i2][j2] - prefix_sum[i1-1][j2] - prefix_sum[i2][j1-1] 
                + prefix_sum[i1-1][j1-1];
}

void build_2D_prefix_sum_array(vector<vector<ll>>& A, int N, int M) {
    for (int i = 1; i < N+1; i++)
        for (int j = 1; j < M+1; j++)
            prefix_sum[i][j] = A[i-1][j-1] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<vector<ll>> A(N, vector<ll>(M, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    build_2D_prefix_sum_array(A, N, M);

    int Q;
    cin >> Q;

    int i1, j1, i2, j2;
    for (int i = 0; i < Q; i++) {
        cin >> i1 >> j1 >> i2 >> j2;
        cout << query(i1, j1, i2, j2) << endl;
    }
    
    return 0;
}