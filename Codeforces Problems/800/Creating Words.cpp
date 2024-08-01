// Creating Words (https://codeforces.com/problemset/problem/1985/A)
 
#include <iostream>
#include <algorithm>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(string& A, string& B) {
    swap(A[0], B[0]);
    cout << A << " " << B << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        string A, B;
        cin >> A >> B;
        
        solve(A, B);
    }
    
    return 0;
}