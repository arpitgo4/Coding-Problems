// mia (https://open.kattis.com/problems/mia)
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
bool isDoubles(int r1, int r2) {
    return r1 == r2;
}

void findWinner(
    int pl1_r1, 
    int pl1_r2, 
    int pl2_r1, 
    int pl2_r2) {

    int winner = 0;
    bool p1_double = false,
         p2_double = false;

    int pl1_score = (max(pl1_r1, pl1_r2) * 10) + (min(pl1_r1, pl1_r2));
    int pl2_score = (max(pl2_r1, pl2_r2) * 10) + (min(pl2_r1, pl2_r2));

    if (pl1_score == 21) {
        winner = 1;
    } else if (pl2_score == 21) {
        winner = 2;
    } else if ((p1_double = isDoubles(pl1_r1, pl1_r2)) || (p2_double = isDoubles(pl2_r1, pl2_r2))) {
        if (p1_double && !p2_double) {
            winner = 1;
        } else if (!p1_double && p2_double) {
            winner = 2;
        }
    } else {
        if (pl1_score > pl2_score) {
            winner = 1;
        } else if (pl1_score < pl2_score) {
            winner = 2;
        }
    }

    if (winner == 0) {
        cout << "Tie." << endl;
    } else {
        cout << "Player " << winner << " wins." << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int pl1_r1, pl1_r2, pl2_r1, pl2_r2;
    cin >> pl1_r1 >> pl1_r2 >> pl2_r1 >> pl2_r2;

    while (pl1_r1 > 0 && pl1_r2 > 0 && pl2_r1 > 0 && pl2_r2 > 0) {
        findWinner(pl1_r1, pl1_r2, pl2_r1, pl2_r2);

        cin >> pl1_r1 >> pl1_r2 >> pl2_r1 >> pl2_r2;
    }
    
    return 0;
}