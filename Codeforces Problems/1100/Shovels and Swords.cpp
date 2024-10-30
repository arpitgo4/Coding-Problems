// Shovels and Swords (https://codeforces.com/problemset/problem/1366/A)
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
/**
 * Shovel: 2 sticks, 1 diamond
 * Sword: 1 stick, 2 diamonds
 * 
 * Each tool solds at same price
 * 
 * `a` sticks 
 * `b` diamonds
 * 
 * a/2 + b = x1
 * a + b/2 = x2
 * 
 * maximize (x1 + x2)
 * 
 * or we can re-write above equations as,
 * 
 * max(a,b)/2 + min(a,b) = x
 * 
 * keep running the equation till one of the values
 * become zero
 * 
 * Since, at each iteration we reducing one of the value
 * by half, overall time complexity for the algorithm 
 * should be O(logN)
 * 
 * Observations,
 * 1. Number of emeralds <= a
 * 2. Number of emeralds <= b
 * 3. Number of emeralds <= (a + b)/3
 * 
 * 2x (stick) + x (diamond) = x
 * 2y (diamond) + y (stick) = y
 * 
 * (a+b)/3 => as in total count of objects can be divided up
 *            into tuples of 3. Each tuple represent a count 
 *            for an emerald that can be earned for that tuple
 *            By division, we will get the count of such tuples
 *            which will represent our emerald
 */

void solve(int a, int b) {
    int count = min(a, min(b, (a+b)/3 ));
    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int a, b;
        cin >> a >> b;
    
        solve(a, b);
    }
    
    return 0;
}