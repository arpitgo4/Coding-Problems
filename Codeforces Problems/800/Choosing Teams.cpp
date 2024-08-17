// Choosing Teams (https://codeforces.com/problemset/problem/432/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(vector<int>& A, int N, int K) {
    int mem_count = 0;
    for (int i = 0; i < N; i++) {
        if (5-A[i] >= K)
            mem_count++;
    }
    
    cout << (mem_count / 3) << endl;
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