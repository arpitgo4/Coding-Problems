//  pairingsocks (https://open.kattis.com/problems/pairingsocks)
 
#include <iostream>
#include <stack>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
void solve(stack<int>& socks_pile, int sock_pair_cnt) {
    stack<int> aux_pile;
    for (int i = 0; i < 2 * sock_pair_cnt; i++) {
        if (!aux_pile.empty() && aux_pile.top() == socks_pile.top()) {
            aux_pile.pop();
            socks_pile.pop();
        } else {
            int sock = socks_pile.top();
            socks_pile.pop();
            aux_pile.push(sock);
        }
    }

    if (socks_pile.empty() && aux_pile.empty()) {
        cout << (2 * sock_pair_cnt) << endl;
    } else {
        cout << "impossible" << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int sock_pair_cnt;
    cin >> sock_pair_cnt;

    stack<int> socks_pile;
    int sock_type_1, sock_type_2;
    for (int i = 0; i < sock_pair_cnt; i++) {
        cin >> sock_type_1 >> sock_type_2;
        socks_pile.push(sock_type_1);
        socks_pile.push(sock_type_2);
    }

    solve(socks_pile, sock_pair_cnt);
    
    return 0;
}