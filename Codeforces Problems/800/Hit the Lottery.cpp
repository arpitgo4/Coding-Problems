// Hit the Lottery (https://codeforces.com/problemset/problem/996/A)

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)

/**
 * We will get count for each bill in every iteration.
 * Time complexity for the algorithm then becomes number
 * of bills, which are constant.
 */

void solve(int N) {
    int count = 0;

    vector<int> bills{1, 5, 10, 20, 100};
    for (int i = 4; i >= 0; i--) {
        count += (N / bills[i]);
        N = (N % bills[i]);
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    solve(N);        
    
    return 0;
}