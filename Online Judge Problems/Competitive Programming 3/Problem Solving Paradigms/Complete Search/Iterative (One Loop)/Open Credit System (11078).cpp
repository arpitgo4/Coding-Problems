// Open Credit System (11078) (https://onlinejudge.org/external/110/11078.pdf)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
void solve(vector<int>& A, int N) {
    vector<int> R_MIN(N, A[N-1]), 
                R_MAX(N, A[N-1]);

    for (int i = N-2; i >= 0; i--) {
        R_MIN[i] = min(R_MIN[i+1], A[i]);
        R_MAX[i] = max(R_MAX[i+1], A[i]);
    }

    int max_val = INT_MIN;
    for (int i = 0; i < N-1; i++)
        max_val = max(max_val, 
                    max(A[i]-R_MIN[i+1], A[i]-R_MAX[i+1]));

    cout << max_val << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
    
        solve(A, N);
    }
    
    return 0;
}