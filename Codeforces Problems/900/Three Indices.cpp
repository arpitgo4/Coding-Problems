// Three Indices (https://codeforces.com/problemset/problem/1380/A)
 
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
// Time: O(N^2)
// Space: O(1)

void solve(vector<int>& A, int N) {
    for (int j = 1; j <= N-2; j++) {
        int i = j-1;
        while (i >= 0 && A[i] > A[j])
            i--;

        int k = j+1;
        while (k < N && A[j] < A[k])
            k++;

        if (i >= 0 && k < N) {
            cout << "YES" << endl;
            cout << (i+1) << " " << (j+1) << " " << (k+1) << endl;
            return;
        }
    }

    cout << "NO" << endl;
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