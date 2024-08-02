// Two Arrays And Swaps (https://codeforces.com/problemset/problem/1353/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
void solve(vector<int>& A, vector<int>& B, int K, int N) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int l = 0, h = N-1;
    for (int i = 0; i < K; i++) {
        if (A[l] < B[h]) {
            swap(A[l], B[h]);
            l++;
            h--;
        }
    }

    int sum = 0;
    for (int a : A)
        sum += a;

    cout << sum << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        for (int i = 0; i < N; i++)
            cin >> B[i];
    
        solve(A, B, K, N);
    }
    
    return 0;
}
