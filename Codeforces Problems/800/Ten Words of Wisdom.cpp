// Ten Words of Wisdom (https://codeforces.com/problemset/problem/1850/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(vector<int>& A, vector<int>& B, int N) {
    vector<int> C;
    for (int i = 0; i < N; i++)
        if (A[i] <= 10)
            C.push_back(i);

    int M = C.size();
    int max_idx = -1, max_val = -1;
    for (int i = 0; i < M; i++) {
        if (max_val < B[C[i]]) {
            max_val = B[C[i]];
            max_idx = C[i];
        }
    }

    cout << (max_idx+1) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++)
            cin >> A[i] >> B[i];
    
        solve(A, B, N);
    }
    
    return 0;
}