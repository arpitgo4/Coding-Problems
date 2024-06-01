// Yet Another Card Deck (https://codeforces.com/problemset/problem/1511/C)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
/**
 * Card -> { index, color }
 * 
 * Query -> color => card with min index and given color
 * 
 * Approach 1,
 * 1. Linked list for connected nature, can easily move elements to front, also gives the 
 *    global index for the card and index of card is maintained by the order in which in appears
 *    in the list not by an index of indexed data structure
 * 2. Every search takes O(N) time, placing card at top takes O(1)
 * 
 * Time: O(N * Q)
 * Space: O(N)
 * 
 * Speed up searching,
 * 1. We only need to find the top most card for any color. Can we maintain a data structure to 
 *    cache this information for every color and update it as well when we move the card to top
 *    of the deck.
 * 
 * Search will take: O(1)
 * Re-placing card: O(N) (not way to speed this up)
 * Update index of top card: O(1)
 * 
 * Linked List + Unordered Map
 * 
 * Approach 2,
 * 
*/

// Time: O(KQ)                          // K -> number of possible colors in deck, [1, 50]
// Space: O(1)

int solve(vector<int>& colors, int N, int q) {
    vector<int>::iterator itr = find(colors.begin(), colors.end(), q);
    rotate(colors.begin(), itr, itr+1);

    return itr - colors.begin() + 1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    vector<int> colors(N);
    for (int i = 0; i < N; i++)
        cin >> colors[i];

    int q;
    for (int i = 0; i < Q; i++) {
        cin >> q;
        cout << solve(colors, N, q) << " ";
    }

    cout << endl;
    
    return 0;
}