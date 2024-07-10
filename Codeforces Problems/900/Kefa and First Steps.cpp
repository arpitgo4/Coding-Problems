// Kefa and First Steps (https://codeforces.com/problemset/problem/580/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(vector<int>& A, int N) {
    int j = 0, max_len = 1;
    for (int i = 1; i < N; i++) {
        if (A[i] < A[i-1])
            j = i;

        int len = i-j+1;
        max_len = max(max_len, len);
    }

    cout << max_len << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);
    
    return 0;
}