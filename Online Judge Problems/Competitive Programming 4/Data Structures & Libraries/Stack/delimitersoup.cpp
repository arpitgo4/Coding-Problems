// delimitersoup (https://open.kattis.com/problems/delimitersoup)
 
#include <iostream>
#include <vector>
#include <string>
#include <stack>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
bool isOpenBracket(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

char getOpeningBracket(char ch) {
    if (ch == ')')
        return '(';
    else if (ch == ']')
        return '[';
    else return '{';
}

void solve(string& prog_code, int prog_len) {
    stack<pair<char,int>> code_stack;
    for (int i = 0; i < prog_len; i++) {
        char code_ch = prog_code[i];
        if (code_ch == ' ')
            continue;

        if (isOpenBracket(code_ch)) {
            code_stack.push({ code_ch, i });
        } else {                                                         // closing bracket
            char openingBracket = getOpeningBracket(code_ch);
            if (code_stack.empty() || 
                    openingBracket != code_stack.top().first) {

                cout << code_ch << " " << i << endl;
                return;
            }

            code_stack.pop();
        }
    }

    cout << "ok so far" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int prog_len;
    cin >> prog_len;

    cin.ignore();

    string prog_code;
    getline(cin, prog_code);

    solve(prog_code, prog_len);
    
    return 0;
}