// evenup (https://open.kattis.com/problems/evenup)
 
#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
void solve(vector<int>& cards, int card_cnt) {
    stack<int> card_stack;
    for (int i = 0; i < card_cnt; i++) {
        if (!card_stack.empty() && 
                ((card_stack.top() + cards[i]) % 2) == 0) {
            card_stack.pop();
        } else {
            card_stack.push(cards[i]);
        }
    }

    cout << card_stack.size() << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int card_cnt;
    cin >> card_cnt;

    vector<int> cards(card_cnt);
    for (int i = 0; i < card_cnt; i++) {
        cin >> cards[i];
    }

    solve(cards, card_cnt);
    
    return 0;
}