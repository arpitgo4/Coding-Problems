// backspace (https://open.kattis.com/problems/backspace)
 
#include <iostream>
#include <deque>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input_str;
    cin >> input_str;

    int input_len = input_str.length();
    deque<char> char_deque;
    for (int i = 0; i < input_len; i++) {
        if (input_str[i] == '<') {
            char_deque.pop_back();
        } else {
            char_deque.push_back(input_str[i]);
        }
    }

    while (!char_deque.empty()) {
        cout << char_deque.front();
        char_deque.pop_front();
    }
    cout << endl;
    
    return 0;
}