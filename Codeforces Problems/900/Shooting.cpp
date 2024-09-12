// Shooting (https://codeforces.com/problemset/problem/1216/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
void solve(vector<int>& A, int N) {
    vector<int> P(N, -1);
    for (int i = 0; i < N; i++)
        P[i] = i;

    sort(P.begin(), P.end(), [&](const int i, const int j) {
        return A[i] > A[j];
    });

    int cost = 0;
    for (int i = 0; i < N; i++)
        cost += (A[P[i]] * i + 1);

    cout << cost << endl;
    for (int i = 0; i < N; i++)
        cout << (P[i]+1) << " ";
    cout << endl;
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