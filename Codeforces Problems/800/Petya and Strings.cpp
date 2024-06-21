// Petya and Strings (https://codeforces.com/problemset/problem/112/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
  
void solve(string& A, string& B) {
   int N = A.length();
   for (int i = 0; i < N; i++) {
        char a = tolower(A[i]);
        char b = tolower(B[i]);
        if (a < b) {
            cout << "-1" << endl;
            return;
        } else if (a > b) {
            cout << "1" << endl;
            return;
        }
   } 

   cout << "0" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string A, B;
    cin >> A >> B;

    solve(A, B);
    
    return 0;
}