// Triple (https://codeforces.com/problemset/problem/1669/B)
 
#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
void solve(vector<int>& A, int N) {
    unordered_map<int,int> uMap;
    for (int a : A) {
        uMap[a]++;
        if (uMap[a] == 3) {
            cout << a << endl;
            return;
        }
    }

    cout << -1 << endl;
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