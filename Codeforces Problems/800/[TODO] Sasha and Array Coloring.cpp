// Sasha and Array Coloring (https://codeforces.com/problemset/problem/1843/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O()
// Space: O()
 
void solve(vector<int>& A, int N) {
    
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