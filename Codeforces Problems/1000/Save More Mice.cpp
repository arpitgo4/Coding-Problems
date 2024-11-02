// Save More Mice (https://codeforces.com/problemset/problem/1593/C)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
typedef long long ll;

void solve(vector<int>& A, int N, int M) {
    sort(A.begin(), A.end());

    int count = 0;
    ll cat_i = 0;
    for (int i = N-1; i >= 0 && cat_i < M; i--) {
        int d = M-A[i];
        if (cat_i < A[i])
            count++;
        
        cat_i += d;
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int M, N;
        cin >> M >> N;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
    
        solve(A, N, M);
    }
    
    return 0;
}