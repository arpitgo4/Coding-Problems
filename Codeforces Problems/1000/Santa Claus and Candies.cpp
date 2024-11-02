// Santa Claus and Candies (https://codeforces.com/problemset/problem/753/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(int x) {
    int y = 1;
    while (y * (y+1) <= 2 * x)
        y++;

    y--;
    cout << y << endl;

    for (int i = 1; i < y; i++) {
        cout << i << " ";
        x -= i;
    }

    cout << x << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    solve(N);
    
    return 0;
}