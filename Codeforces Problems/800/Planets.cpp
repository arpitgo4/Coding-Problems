// Planets (https://codeforces.com/problemset/problem/1730/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
const int MAX_P = 100;

void solve(vector<int>& A, int N, int C) {
    vector<int> cnt(MAX_P+1, 0);
    for (int a : A)
        cnt[a]++;

    int cost = 0;
    for (int i = 0; i <= MAX_P; i++)
        cost += cnt[i] >= C ? C : cnt[i];

    cout << cost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, C;
        cin >> N >> C;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N, C);
    }
    
    return 0;
}