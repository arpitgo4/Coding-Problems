// Queries about less or equal elements (https://codeforces.com/problemset/problem/600/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN + MlogN)
// Space: O(1)
 
void solve(vector<int>&A, int N, vector<int>& B, int M) {
    sort(A.begin(), A.end());

    for (int b : B) {
        auto itr = upper_bound(A.begin(), A.end(), b);
        cout << (itr - A.begin()) << " ";
    }

    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < M; i++)
        cin >> B[i];

    solve(A, N, B, M);
    
    return 0;
}