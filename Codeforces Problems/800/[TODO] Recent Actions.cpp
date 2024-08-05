// Recent Actions (https://codeforces.com/problemset/problem/1799/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O()
// Space: O()
 
void solve(vector<int>& A, int M, int N) {
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> A(M);
        for (int i = 0; i < M; i++)
            cin >> A[i];

        solve(A, M, N);
    }
    
    return 0;
}