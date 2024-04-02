// Splitting an Array (https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B)
 
#include <iostream>
#include <vector>
 
using namespace std;

// M = 1e14
// Time: O(N + KlogNlogM)
// Space: O(N)

typedef long long ll;
 
vector<ll> PS;

void compute_prefix_sum(vector<ll>& A, int N) {
    PS.assign(N, 0);
    for (int i = 0; i < N; i++) {
        if (i == 0)
            PS[i] = A[i];
        else PS[i] = PS[i-1] + A[i];
    }
}

ll query(int l, int h) {
    if (l == 0)
        return PS[h];
    return PS[h] - PS[l-1];
}

int binary_search(ll sum, int l, int h) {
    int init_l = l;
    while (l <= h) {
        int m = (h-l)/2 + l;
        if (query(init_l, m) <= sum)
            l = m+1;
        else h = m-1;
    }

    return h;
}

bool can_split(ll m, int N, int K) {
    int l = 0, h = N-1, i = 0;
    for (; i < K && l < N; i++) {
        l = binary_search(m, l, h);
        l++;
    }

    return i == K;
}

void solve(vector<ll>& A, int N, int K) {
    compute_prefix_sum(A, N);

    ll l = 0, h = 1e14;
    while (l <= h) {
        ll m = (h-l)/2 + l;
        cout << "m: " << m << endl;
        if (can_split(m, N, K))
            l = m+1;
        else h = m-1;
    }

    cout << h << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, K);
    
    return 0;
}