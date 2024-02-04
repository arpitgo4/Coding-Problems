// Coprime Segment (https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
 
using namespace std;

typedef long long ll;
 
/**
 * Notes,
    ** Idea is, **
    ** Any segment with atleast one coprime pair will have it's gcd = 1. **
    ** Fix one end of the segment and find the closest (binary search) end for **
    ** this segment with a co-prime pair. **
 * 
 *  // this search depends on hitting gcd(seg) == 1 for shrinking,
    // otherwise it will keep the j pointer at 0
    // and will not consider segments starting at other jth positions
    while (w_size > 1 && query(j, i) == 1) {
        min_len = min(min_len, w_size);
        j++;
        w_size = i-j+1;
    }

    ** Debugging Ideas (WA for test case 19) **
    * No problem with long long numbers. Works for test case,
        4
        100000000000000 100000000000000 1000000000000000000 11
        => 2
    
*/

// Time: O(logX * NlogN)                    // logX = log(max(a))
// Space: O(NlogN)
 
// sparse table with gcd of segments
vector<vector<ll>> sparse_table;

void print_vector(vector<vector<ll>>& A) {
    for (auto& v : A) {
        for (ll a : v)
            cout << a << " ";
        cout << endl;
    }
}

// Time: O(log(max(a, b)))
// Space: O(log(max(a, b)))
ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void build_sparse_table(vector<ll>& A, int N) {
    int max_pow = ceil(log2(N));
    sparse_table.assign(max_pow+1, vector<ll>(N, 0));

    for (int i = 0; i < N-1; i++)
        sparse_table[0][i] = A[i];

    for (int i = 0; i < N-1; i++)
        sparse_table[1][i] = gcd(A[i], A[i+1]);

    for (int pow = 2; pow <= max_pow; pow++)
        for (int i = 0; i < N; i++) {
            ll a = sparse_table[pow-1][i];
            ll b = 0;
            int b_idx = i + (1 << (pow-1));
            if (b_idx < N)
                b = sparse_table[pow-1][b_idx];

            if (b != 0)
                sparse_table[pow][i] = gcd(a, b);
        }
}

ll query_gcd(int i, int j) {
    int w_size = j-i+1;
    int pow = log2(w_size);

    ll a = sparse_table[pow][i];
    ll b = sparse_table[pow][j-(1 << pow)+1];

    return gcd(a, b);
}

// l & h represents boundaries for search space
void solve(vector<ll>& A, int N) {
    build_sparse_table(A, N);

    if (query_gcd(0, N-1) != 1) {
        cout << -1;
        return;
    }

    int min_len = INT_MAX, j = 0;
    for (int i = 0; i < N-1; i++) {
        int l = i+1, h = N-1;
        if (query_gcd(i, h) != 1)
            continue;

        while (l <= h) {
            int m = (h-l)/2 + l;
            ll seg_gcd = query_gcd(i, m);               // segment's start index (i) and ending index (m) are used
            if (seg_gcd == 1)
                h = m-1;
            else l = m+1;
        }

        // l will hold the ending index for segment
        if (l < N && query_gcd(i, l) == 1)
            min_len = min(min_len, l-i+1);
    }

    cout << (min_len == INT_MAX ? -1 : min_len);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);
    
    return 0;
}