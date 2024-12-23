// Woodcutters (https://codeforces.com/problemset/problem/545/C)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N * 3) ~ O(N)
// Space: O(N * 3) ~ O(N)
 
/**
 * We need to assign a direction for trees to fall.
 * Set of directions is a combination.
 * We need to find the combination which allows for
 * maximum trees to be cut.
 * 
 * Each tree can be assigned { left, right, not-cut }
 * one of these directions.
 * 
 * Brute-force backtracking solution will yield run-time
 * of, O(2^N)
 * 
 * 
 * This problem can be visualized as intervals/segments. Each
 * segment has to moved left/right or kept vertical, such that
 * no intervals should overlap at the end.
 * 
 * Initially, each interval is { xi, xi } i.e. vertical,
 * left orientation: { xi-hi, xi }
 * right orientation: { xi, xi+hi }
 * 
 * Orientation representations,
 * 0 -> vertical
 * 1 -> left
 * 2 -> right
 */

vector<vector<int>> dp;

bool does_overlap(int i1, int j1, int i2, int j2) {
    return j1 >= i2;
}

int dfs(int i, int orien, vector<int>& A, vector<int>& C, int N) {
    if (i == N)
        return 0;
    if (dp[i][orien] != -1)
        return dp[i][orien];

    // solve for child problem first, for each orientation
    dfs(i+1, 0, A, C, N);
    dfs(i+1, 1, A, C, N);
    dfs(i+1, 2, A, C, N);

    // then current problem will decide based on what 
    // orientations are available to it

    // can fall right
    if (i < N-1) {

    } else {
        // we can definitely fall right

    }

    // sub-problem merge logic will be complex for this problem 

    // 1. check if it can fall to right
    //    if yes, then choose vertical and right orientation for next tree
    //    also, if left orientation for next tree also doens't interfere with this

    // 2. check if it can fall to left
    //    if yes...


    // maximize from all the above possiblities

    int count = 0;
    int vertical = dfs(i+1, 0, A, C, N);
    int left = 1 + dfs(i+1, )

    return dp[i][orien] = count;
}

void solve(vector<int>& A, vector<int>& C, int N) {
    dp.assign(N+1, vector<int>(3, -1));

    int a = dfs(0, 0, A, C, N);
    int b = dfs(0, 1, A, C, N);
    int c = dfs(0, 2, A, C, N);

    int count = max(a, max(b, c));
    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> C(N), A(N);
    for (int i = 0; i < N; i++)
        cin >> C[i] >> A[i];

    solve(A, C, N);
    
    return 0;
}