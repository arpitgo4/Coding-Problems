// Sale (https://codeforces.com/problemset/problem/34/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
void solve(vector<int>& A, int N, int M) {
    sort(A.begin(), A.end());

    int max_sum = 0;
    for (int i = 0; i < min(N, M); i++)
        if (A[i] < 0)
            max_sum += A[i];

    cout << abs(max_sum) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, M);
    
    return 0;
}