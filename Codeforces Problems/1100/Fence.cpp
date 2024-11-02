// Fence (https://codeforces.com/problemset/problem/363/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(vector<int>& A, int N, int K) {
    int min_idx = 0, min_val = 0;
    for (int i = 0; i < K; i++)
        min_val += A[i];

    int curr_val = min_val;
    for (int i = K; i < N; i++) {
        curr_val -= A[i-K];
        curr_val += A[i];
        if (curr_val < min_val) {
            min_val = curr_val;
            min_idx = i-K+1;
        }
    }

    cout << (min_idx + 1) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, K);
    
    return 0;
}