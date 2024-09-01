// Die Roll (https://codeforces.com/problemset/problem/9/A)
 
#include <iostream>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Y, W;
    cin >> Y >> W;
    
    int total = 6;
    int rem = total - max(Y, W) + 1;

    if (rem % 2 == 0 && total % 2 == 0) {
        rem /= 2;
        total /= 2;
    }
    if (rem % 3 == 0 && total % 3 == 0) {
        rem /= 3;
        total /= 3;
    }

    cout << rem << "/" << total << endl;
    
    return 0;
}