// Odd Queries (https://codeforces.com/problemset/problem/1807/D)
 
#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
// Time: O(N)
// Space: O(N)

vector<ll> prefix_sum(vector<ll>& A, int N) {
    vector<ll> prefix_sum_array(N+1, 0);
    for (int i = 1; i < N+1; i++)
        prefix_sum_array[i] = A[i-1] + prefix_sum_array[i-1];

    return prefix_sum_array;
} 

void solve(vector<ll>& prefix_array, int N, int l, int r, int k) {
    int seg_len = r-l+1;
    ll seg_sum = prefix_array[r] - prefix_array[l-1];
    ll total_sum = prefix_array[N-1];
    ll final_sum = total_sum - seg_sum + (k * 1LL * seg_len);

    cout << (final_sum % 2 == 1 ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, Q;
        cin >> N >> Q;

        vector<ll> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        vector<ll> prefix_array = prefix_sum(A, N);

        int l, r, k;
        for (int i = 0; i < Q; i++) {
            cin >> l >> r >> k;

            solve(prefix_array, N+1, l, r, k);
        }
    }   
    
    return 0;
}