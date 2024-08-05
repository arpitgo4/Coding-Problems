// Choose Two Numbers (https://codeforces.com/problemset/problem/1206/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(N + M)
// Space: O(1)
 
void solve(vector<int>& A, int N, vector<int>& B, int M) {
    int max_a = *max_element(A.begin(), A.end());
    int max_b = *max_element(B.begin(), B.end());

    cout << max_a << " " << max_b << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int M;
    cin >> M;

    vector<int> B(M);
    for (int i = 0; i < M; i++)
        cin >> B[i];

    solve(A, N, B, M);
    
    return 0;
}