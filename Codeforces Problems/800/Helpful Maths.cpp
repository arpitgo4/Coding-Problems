// Helpful Maths (https://codeforces.com/problemset/problem/339/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
  
// Time: O(N)
// Space: O(1)
 
void solve(string& S) {
    int N = S.length();

    int count_plus = 0;
    vector<int> table(4, 0);
    for (int i = 0; i < N; i++) {
        if (S[i] == '+') {
            count_plus++;    
        } else {
            int num = S[i] - '0';
            table[num]++;
        }
    }

    for (int i = 1; i < 4; i++) {
        while (table[i]--) {
            cout << i;
            if (count_plus--)
                cout << "+";
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;

    solve(S);
    
    return 0;
}