// Print a Pedestal (https://codeforces.com/problemset/problem/1690/A)
 
#include <iostream>
#include <tuple>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
/**
 * Base case for x = 6
 * 3,2,1
 * (x/2),(x/2-1),(x/2-2)
 * 
 * Maximum possible heights for each pedestal,
 * ~ (x/3-1), (x/3+3), (x/3-2)
 * 
 * let say `y` be the shortest height of first place pedestal, total blocks are `x`
 * first = y;
 * middle = (x-y)
 * third = 
 * 
 * We need to find minimum possible height for tallest pedestal,
 * 
 * Minimum possible height for tallest pedestal,
 * (shortest + 2) and (middle + 1)
 * 
 * find min. height for shortest pedestal,
 * 
 * Can we use Binary Search here,
 * bounds can be [0,(x/3-2)]
 * 
 * first subsegment of the above bounds will not give me 
 * 
 * Some algorithm,
 * 1. Pick a number y, let it be the height of tallest pedestal
 * 2. Remaining blocks (x-y). Divide them in two halves, (x-y)/2
 * 3. Middle and Third pedestal can be, (x-y)/2+1 & (x-y)/2-1
 * 
 * Observations,
 * 1. Tallest pedestal setup possible, x-3, 2, 1
 *    x-y, y+1, y-1
 * 2. Can we come up with bounds for `y` (height of first pedestal)?
 *    Lower Bound for `y`: 3
 *    Upper Bound for `y`: 
 * 
 * All values till the upper bound will get us the desired pedestal setup,
 * we can assume the searching bound to be [3,1e5]
 * 
 * Run binary search on the above seach space to find the upper bound of the 
 * `y` value.
 * 
 * Binary Search on Answer will not work. Answers can not be segmented into two
 * halves with truth values.
 * 
 * Linear scan will do, first value that can build pedestals is the answer.
 */

tuple<int,int,int> heights(int x, int y) {
    int first = y;
    int rem = x-y;
    int second = rem/2 + 1;
    int third;
    if (rem % 2 == 1)
        third = rem/2;
    else third = rem/2 - 1;

    return { first, second, third };
}

bool verify(int x, int y) {
    auto tup = heights(x, y);
    int f, s, t;
    tie(f, s, t) = tup;

    return (f > s && s > t && t > 0);
}

void solve(int x) {
    int y = 3;
    for (; y <= x-3 && !verify(x, y); y++);

    int f, s, t;
    auto tup = heights(x, y);
    tie(f, s, t) = tup;
    cout << s << " " << f << " " << t << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int x;
        cin >> x;
    
        solve(x);
    }
    
    return 0;
}