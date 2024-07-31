// Rook, Bishop and King (https://codeforces.com/problemset/problem/370/A)
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)

/**
 * Approaches,
 * 1. Use 3 BFS runs to calculate shortest path for each piece
 * 2. Use Math and Manhattan Coordinate System logic
 * 
 * Rook: can reach anywhere in either 1 or 2 moves max. 
 *       if end location is along the same row or col as start then 1, otherwise 2
 * Bishop: can only reach end location if start and end are on same color tile, output will be 0
 *         can reach anywhere if above holds in either 1 or 2 moves
 *         if already along the diagonal of starting location then 1 otherwise 2
 * King: can reach anywhere in diagonal number of moves from start and ending locations
 */

void solve(int s_x, int s_y, int e_x, int e_y) {
    // Rook
    if (s_x == e_x || s_y == e_y)
        cout << 1 << " ";
    else cout << 2 << " ";

    // Bishop
    if ((s_x+e_x) % 2 != (s_y+e_y) % 2)
        cout << 0 << " ";
    else {
        if (abs(e_x-s_x) == abs(e_y-s_y))
            cout << 1 << " ";
        else cout << 2 << " ";
    }
    
    // King
    cout << max(abs(e_x-s_x), abs(e_y-s_y)) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int s_x, s_y, e_x, e_y;
    cin >> s_x >> s_y >> e_x >> e_y;

    solve(s_x, s_y, e_x, e_y);
    
    return 0;
}