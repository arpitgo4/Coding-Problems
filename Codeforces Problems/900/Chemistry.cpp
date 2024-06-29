// Chemistry (https://codeforces.com/problemset/problem/1883/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& S, int N, int K) {
    vector<int> table(26, 0);
    for (char c : S)
        table[c-'a']++;

    // valid palindrome: 1 odd, rest even char count
    // valid palindrome: all even char count

    int odd_count = 0, even_count = 0;
    for (int v : table)
        if (v % 2 == 0)
            even_count++;
        else odd_count++;

    if (odd_count > K+1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        string S;
        cin >> S;

        solve(S, N, K);
    }
    
    return 0;
}