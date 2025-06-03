// reversebinary (https://open.kattis.com/problems/reversebinary)
 
#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(int num) {
    stack<int> reverse_num_stack;
    while (num > 0) {
        if (num & 1) {
            reverse_num_stack.push(1);
        } else {
            reverse_num_stack.push(0);
        }

        num >>= 1;
    }

    int reverse_num = 0;
    int idx = 0;
    while (!reverse_num_stack.empty()) {
        if (reverse_num_stack.top() == 1) {
            reverse_num |= (1 << idx);
        }

        reverse_num_stack.pop();
        idx++;
    }
    cout << reverse_num << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num;
    cin >> num;

    solve(num);
    
    return 0;
}