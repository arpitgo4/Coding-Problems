// circuitmath (https://open.kattis.com/problems/circuitmath)
 
#include <iostream>
#include <vector>
#include <string>
#include <stack>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
char applyNotOperation(char ch) {
    if (ch == 'T')
        return 'F';
    else return 'T';
}

char applyOrOperator(char a, char b) {
    if (a == 'F' && b == 'F')
        return 'F';
    return 'T';
}

char applyAndOperator(char a, char b) {
    if (a == 'T' && b == 'T')
        return 'T';
    return 'F';
}

char applyBinaryOperator(char a, char b, char op) {
    if (op == '+') {
        return applyOrOperator(a, b);
    } else {
        return applyAndOperator(a, b);
    }
}

bool isUnaryOperator(char ch) {
    return ch == '-';
}

bool isOperator(char ch) {
    return ch == '*' || ch == '+' || ch == '-';
}

void solve(
    string& expression,
    vector<char>& inputs,
    int input_var_cnt
) {

    stack<char> exp_stack;
    int exp_len = expression.length();

    for (int i = 0; i < exp_len; i++) {
        char ch = expression[i];
        if (ch == ' ')
            continue;

        if (isOperator(ch)) {
            if (isUnaryOperator(ch)) {
                char top_ch = exp_stack.top();
                exp_stack.pop();
                char not_top_ch = applyNotOperation(top_ch);
                exp_stack.push(not_top_ch);
            } else {
                char top_ch_a = exp_stack.top();
                exp_stack.pop();
                char top_ch_b = exp_stack.top();
                exp_stack.pop();
                char result = applyBinaryOperator(top_ch_a, top_ch_b, ch);
                exp_stack.push(result);
            }
        } else {
            exp_stack.push(inputs[ch - 'A']);
        }
    }

    cout << exp_stack.top() << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int input_var_cnt;
    cin >> input_var_cnt;

    vector<char> inputs(input_var_cnt);
    for (int i = 0; i < input_var_cnt; i++) {
        cin >> inputs[i];
    }

    cin.ignore();
    
    string expression;
    getline(cin, expression);

    solve(expression, inputs, input_var_cnt);
    
    return 0;
}