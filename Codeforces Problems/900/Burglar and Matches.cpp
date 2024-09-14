// Burglar and Matches (https://codeforces.com/problemset/problem/16/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
void solve(vector<int>& A, vector<int>& B, int N, int K) {
    vector<int> P(N);
    for (int i = 0; i < N; i++)
        P[i] = i;

    sort(P.begin(), P.end(), [&](const int i, const int j) {
        return B[i] > B[j];
    });

    int count = 0;
    for (int i : P) {
        int num = min(K, A[i]);
        count += B[i] * num;
        K -= num;
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> K >> N;
    
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];

    solve(A, B, N, K);
    
    return 0;
}