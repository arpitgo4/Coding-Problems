// Dictionary (https://codeforces.com/problemset/problem/1674/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(string& word) {
    int pos = 25 * (word[0]-'a');
    if (word[1] > word[0]) {
        pos += (word[1] - 'a');
    } else {
        pos += (word[1] - 'a' + 1);
    }

    cout << pos << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_cnt;
    cin >> test_cnt;
    
    while (test_cnt > 0) {
        string word;
        cin >> word;

        solve(word);

        test_cnt--;
    }
    
    return 0;
}