// ICPC Balloons (https://codeforces.com/problemset/problem/1703/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

int solve(string& S, int N) {
    int count = 0;
    vector<int> table(26, 0);
    for (char c : S) {
        if (table[c - 'A'] == 0)
            count += 2;
        else count++;

        table[c - 'A']++;
    }

    return count;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, N;
    cin >> T;

    string S;
    while (T--) {
        cin >> N >> S;
        cout << solve(S, N) << endl;
    }   
    
    return 0;
}