// Three Friends (https://codeforces.com/problemset/problem/1272/A)
 
#include <iostream>
#include <climits>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
int dist(int a, int b, int c) {
    return abs(a-b) + abs(b-c) + abs(c-a);
}

void solve(int a, int b, int c) {
    int min_dist = INT_MAX;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            for (int k = -1; k <= 1; k++) {
                min_dist = min(min_dist, dist(a+i, b+j, c+k));
            }

    cout << min_dist << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
    
        solve(a, b, c);
    }
    
    return 0;
}