// Segments with Small Spread (https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
 
using namespace std;

typedef long long ll;
 
// Time: O(NlogN + N)
// Space: O(NlogN)
 
/**
 * Idea: build sparse table with min & max values in O(1)
 * 
 * brute-force algorithm will take O(N^2) time compared to
 * sparse table approach will only take O(NlogN)
 * 
 * Sparse table will give better performace as values are constant
 * and each query will only take O(1) time compared to segment tree O(logN)
 * Only caveat, sparse table pre-processing takes O(NlogN) time compared
 * to O(N) for segment trees.
*/

vector<vector<ll>> min_sp_table, max_sp_table;

void build_sparse_table(vector<ll>& A, int N) {
    int max_pow = ceil(log2(N));
    min_sp_table.assign(max_pow+1, vector<ll>(N, LLONG_MAX));
    max_sp_table.assign(max_pow+1, vector<ll>(N, LLONG_MIN));

    for (int i = 0; i < N; i++)
        min_sp_table[0][i] = max_sp_table[0][i] = A[i];

    for (int pow = 1; pow <= max_pow; pow++)
        for (int i = 0; i < N; i++) {
            ll a = min_sp_table[pow-1][i];
            int b_idx = i + (1 << (pow-1));
            ll b = LLONG_MAX;
            if (b_idx < N)
                b = min_sp_table[pow-1][b_idx];

            min_sp_table[pow][i] = min(a, b);

            a = max_sp_table[pow-1][i];
            b_idx = i + (1 << (pow-1));
            b = LLONG_MIN;
            if (b_idx < N)
                b = max_sp_table[pow-1][b_idx];

            max_sp_table[pow][i] = max(a, b);
        }
}

ll query_min(int i, int j) {
    int w_size = j-i+1;
    int pow = log2(w_size);
    ll a = min_sp_table[pow][i];
    ll b = min_sp_table[pow][j-(1 << pow)+1];

    return min(a, b);
}

ll query_max(int i, int j) {
    int w_size = j-i+1;
    int pow = log2(w_size);
    ll a = max_sp_table[pow][i];
    ll b = max_sp_table[pow][j-(1 << pow)+1];

    return max(a, b);
}

void solve(vector<ll>& A, int N, ll K) {
    build_sparse_table(A, N);

    ll count = 0;
    int j = 0;
    for (int i = 0; i < N; i++) {
        while (query_max(j, i)-query_min(j, i) > K)
            j++;

        int w_size = i-j+1;                         // max-min <= K
        count += w_size;
    }

    cout << count;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; ll K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, K); 
    
    return 0;
}