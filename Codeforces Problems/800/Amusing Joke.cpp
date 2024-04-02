// Amusing Joke (https://codeforces.com/problemset/problem/141/A)
 
#include <iostream>
#include <vector>
#include <unordered_set>
 
using namespace std;
  
// Time: O(N)
// Space: O(N)
 
bool can_form_string(unordered_multiset<char>& uMs, string& str) {
    for (char c : str) {
        if (uMs.find(c) == uMs.end())
            return false;
        
        uMs.erase(uMs.find(c));
    }

    return true;
}

void solve(string& guest, string& host, string& letters) {
    unordered_multiset<char> uMs;
    for (char c : letters)
        uMs.insert(c);

    if (can_form_string(uMs, host) && can_form_string(uMs, guest) && uMs.size() == 0)
        cout << "YES";
    else cout << "NO";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string guest, host, letters;
    cin >> guest >> host >> letters;

    solve(guest, host, letters);   
    
    return 0;
}