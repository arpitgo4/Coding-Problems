// Polycarp and Sums of Subsequences (https://codeforces.com/problemset/problem/1618/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)

void solve(vector<int>& A) {
    cout << A[0] << " " << A[1] << " ";
    cout << (A[0]+A[1] == A[2] ? A[3] : A[2]) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        vector<int> A(7);
        for (int i = 0; i < 7; i++)
            cin >> A[i];
    
        solve(A);
    }
    
    return 0;
}