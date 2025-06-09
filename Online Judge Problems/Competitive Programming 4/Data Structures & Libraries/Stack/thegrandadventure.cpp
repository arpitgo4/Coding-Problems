// thegrandadventure (https://open.kattis.com/problems/thegrandadventure)
 
#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
void solve(string& adventure_desc) {
    bool adventure_successfull = true;
    stack<char> adventure_stack;
    for (char ch : adventure_desc) {
        if (ch == '$' || ch == '|' || ch == '*') {
            adventure_stack.push(ch);
        } else if (ch == 't') {
            if (!adventure_stack.empty() && adventure_stack.top() == '|') {
                adventure_stack.pop();
            } else {
                adventure_successfull = false;
                break;
            }
        } else if (ch == 'b') {
            if (!adventure_stack.empty() && adventure_stack.top() == '$') {
                adventure_stack.pop();
            } else {
                adventure_successfull = false;
                break;
            }
        } else if (ch == 'j') {
            if (!adventure_stack.empty() && adventure_stack.top() == '*') {
                adventure_stack.pop();
            } else {
                adventure_successfull = false;
                break;
            }
        }
    }

    cout << (adventure_successfull && adventure_stack.empty() ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int adventure_cnt;
    cin >> adventure_cnt;

    string adventure_desc;
    for (int i = 0; i < adventure_cnt; i++) {
        cin >> adventure_desc;
        solve(adventure_desc);
    }
    
    return 0;
}