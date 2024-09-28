// Phone Desktop (https://codeforces.com/problemset/problem/1974/A)
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
/**
 * Screen size: 5 x 3
 * 
 * Greedy approach, 
 * Put 2x2 tiles first, because 1x1 tiles can always fit in remaining space
 * If we put 1x1 tiles first, 2x2 might not fit and waste space. Leading to
 * non-optimal number of screens.
 * 
 * Total screen space: 15 tiles (1x1)
 * Each 2x2 tile takes 4 cells on the screen
 * 
 * Minimum no of screen is dependent first on number of y tiles & then on x tiles
 * 1. count = ceil(y / 2)
 * 2. if there is a remainder, i.e. y % 2, we need 1 more screen
 * 3. Each screen with 2 y tiles, has 7 tiles empty for x tiles
 * 4. Screen with 1 y tile, has 11 tiles empty for x tiles
 * 5. Remaining of the x tiles can be distributed in more screens where each screen
 *    will can take 15 x tiles.
 */

void solve(int x, int y) {
    int count = 0;
    
    count += y/2;
    x -= min(x, (y/2) * 7);
    count += y%2;
    if (y%2 == 1)
        x -= min(x, 11);

    count += (x / 15);
    if (x % 15 != 0)
        count++;

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int x, y;
        cin >> x >> y;
    
        solve(x, y);
    }
    
    return 0;
}