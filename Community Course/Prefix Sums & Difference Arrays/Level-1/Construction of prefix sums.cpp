// Construction of prefix sums (https://codeforces.com/edu/course/3/lesson/10/1/practice/contest/324365/problem/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
// Time: O(N)
// Space: O(N)

void solve(vector<ll>& A, int N) {
    vector<ll> prefix_sum(N+1, 0);
    for (int i = 1; i < N+1; i++)
        prefix_sum[i] = prefix_sum[i-1] + A[i-1];

    for (ll a : prefix_sum)
        cout << a << " ";
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