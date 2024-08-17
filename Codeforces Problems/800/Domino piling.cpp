// Domino piling (https://codeforces.com/problemset/problem/50/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
/**
 * Backtracking algorithm is required here, as there are two
 * choices with every step we can take.
 * 
 * DP can optimize the time complexity for the above algorithm.
 * 
 * Greedy can produce the most optimal solution.
 * 
 * Each row domino count: M / 2 and M % 2 => empty cell count (0 or 1)
 * 
 */

void solve(int M, int N) {
    int count = (N / 2) * M;
    int empty_count = (N % 2) * M;
    count += (empty_count / 2);

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M, N;
    cin >> M >> N;
    
    solve(M, N);
    
    return 0;
}