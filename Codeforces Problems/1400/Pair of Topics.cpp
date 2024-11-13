// Pair of Topics (https://codeforces.com/problemset/problem/1324/D)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
/**
 * A[i] + A[j] > B[i] + B[j]
 * 
 * A[i] - B[i] > B[j] - A[j]
 * 
 * C[i] > C[j]
 */

typedef long long ll;

void solve(vector<ll>& A, vector<ll>& B, int N) {
    vector<int> C(N);
    for (int i = 0; i < N; i++)
        C[i] = A[i] - B[i];

    sort(C.begin(), C.end());

    ll count = 0;
    for (int i = 0; i < N; i++) {
        if (C[i] <= 0)
            continue;
        int j = lower_bound(C.begin(), C.end(), -C[i]+1) - C.begin();
        count += i - j;
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<ll> B(N);
    for (int i = 0; i < N; i++)
        cin >> B[i];

    solve(A, B, N);
    
    return 0;
}