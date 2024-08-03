// Only Pluses (https://codeforces.com/problemset/problem/1992/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(vector<int>& A) {
    for (int i = 0; i < 5; i++) {
        auto itr = min_element(A.begin(), A.end());
        (*itr)++;
    }

    cout << (A[0] * A[1] * A[2]) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        vector<int> A(3);
        cin >> A[0] >> A[1] >> A[2];
        
        solve(A);
    }
    
    return 0;
}