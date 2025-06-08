// throwns (https://open.kattis.com/problems/throwns)
 
#include <iostream>
#include <stack>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

/**
 * Negative modular arithmetic is not handled 
 * by-default in C++.
 * 
 * Need to make the result positive before applying
 * modulo operation by adding the circle length.
 * Adding circle length to the result has no side-effect
 * rather than getting the next equivalent value from the 
 * current value.
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int student_cnt, throw_cmd_cnt;
    cin >> student_cnt >> throw_cmd_cnt;

    stack<int> cmd_stack;

    string str;
    for (int i = 0; i < throw_cmd_cnt; i++) {
        cin >> str;
        if (str == "undo") {
            cin >> str;
            int cmd = stoi(str);
            while (cmd > 0) {
                cmd_stack.pop();
                cmd--;
            }
        } else {
            int cmd = stoi(str);
            cmd_stack.push(cmd);
        }
    }

    stack<int> reverse_cmd_stack;
    while (!cmd_stack.empty()) {
        reverse_cmd_stack.push(cmd_stack.top());
        cmd_stack.pop();
    }

    int curr_pos = 0;
    while (!reverse_cmd_stack.empty()) {
        int cmd = reverse_cmd_stack.top();
        if (cmd < 0) {
            curr_pos = (curr_pos + cmd + (10001 * student_cnt)) % student_cnt;    
        } else {
            curr_pos = (curr_pos + cmd) % student_cnt;
        }

        reverse_cmd_stack.pop();
    }

    cout << curr_pos << endl;
    
    return 0;
}