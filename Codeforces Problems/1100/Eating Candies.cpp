// Eating Candies (https://codeforces.com/problemset/problem/1669/F)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)

void solve(vector<int>& A, int N) {
    int count = 0;
    int i = 0, j = N-1;
    int pref = A[i], suff = A[j];
    while (i < j) {
        if (pref == suff) {
            count = max(count, i+1 + N-1-j+1);
            pref += A[++i];
            suff += A[--j];
        } else if (pref < suff) {
            pref += A[++i];
        } else {                                                    // pref > suff
            suff += A[--j];
        }
    }

    cout << count << endl;
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
