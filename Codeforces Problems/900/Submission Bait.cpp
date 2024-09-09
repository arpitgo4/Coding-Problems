// Submission Bait (https://codeforces.com/problemset/problem/1990/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
const int MAX_N = 50 + 1;

void solve(vector<int>& A, int N) {
    vector<int> cnt(MAX_N, 0);
    for (int a : A)
        cnt[a]++;

    bool odd_found = false;
    for (int i = 50; i > 0; i--) {
        if (cnt[i] % 2 == 1)
            odd_found = true;
    }

    cout << (odd_found ? "YES" : "NO") << endl;
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