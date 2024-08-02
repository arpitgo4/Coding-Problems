// Increasing (https://codeforces.com/problemset/problem/1742/B)
 
#include <iostream>
#include <vector>
#include <unordered_set>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
void solve(vector<int>& A, int N) {
    unordered_set<int> uSet;
    for (int a : A) {
        if (uSet.find(a) == uSet.end())
            uSet.insert(a);
        else {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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