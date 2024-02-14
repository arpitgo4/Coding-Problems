// Make it White (https://codeforces.com/contest/1927/problem/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& S, int N) {
    int i = 0, j = N-1;
    while (S[i] != 'B') i++;
    while (S[j] != 'B') j--;

    cout << j-i+1 << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    int N;
    string S;
    while (T--) {
        cin >> N >> S;

        solve(S, N);
    }   
    
    return 0;
}