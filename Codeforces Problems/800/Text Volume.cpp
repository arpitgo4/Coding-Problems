// Text Volume (https://codeforces.com/contest/837/problem/A)
 
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& text, int N) {
    int text_vol = 0, cap_count = 0;
    for (char c : text) {
        if (c == ' ') {
            cap_count = 0;
            continue;
        }

        if (c < 97)
            cap_count++;

        text_vol = max(text_vol, cap_count);
    }

    cout << text_vol << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    cin.ignore();

    string text;
    getline(cin, text);
    
    solve(text, N);
    
    return 0;
}