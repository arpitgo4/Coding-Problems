// To My Critics (https://codeforces.com/problemset/problem/1850/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(vector<int>& A) {
    int max_1 = -1, max_2 = -1;
    for (int i = 0; i < 3; i++) {
        if (max_1 < A[i]) {
            max_2 = max_1;
            max_1 = A[i];
        } else if (max_2 < A[i])
            max_2 = A[i];
    }
    
    cout << (max_1 + max_2 >= 10 ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        vector<int> A(3);
        for (int i = 0; i < 3; i++)
            cin >> A[i];

        solve(A);
    }   
    
    return 0;
}