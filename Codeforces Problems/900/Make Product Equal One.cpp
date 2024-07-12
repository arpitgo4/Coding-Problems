// Make Product Equal One (https://codeforces.com/problemset/problem/1206/B)
 
#include <iostream>
#include <vector>
 
using namespace std;

typedef long long ll;
 
// Time: O(N)
// Space: O(N)
 
/**
 * We need to check number of operations needed to make any A[i]
 * either 1 or -1
 * 
 * A[i] + x = 1
 * x = 1 - A[i]
 * 
 * A[i] + x = -1
 * x = -1 - A[i]
 * 
 * Using Subset backtracking on this will result in O(2^N) complexity.
 * 
 * DP is not applicable on this problem as it form's a binary tree (subset tree)
 * and there are no overlapping subproblems
 * 
 * There is a greedy algorithm that can give minimum for the problem.
 */

void solve(vector<int>& A, int N) {
    int pos_count = 0, neg_count = 0;
    ll cost = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
            neg_count++;
            cost += abs(-1 - A[i]);
            A[i] = -1;
        } else if (A[i] > 0) {
            pos_count++;
            cost += abs(1 - A[i]);
            A[i] = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            if (neg_count % 2 == 1) {
                A[i] = -1;
                cost++;
                neg_count++;
            } else {
                A[i] = 1;
                cost++;
                pos_count++;
            }
        }
    }

    if (neg_count % 2 == 1)
        cost += 2;

    cout << cost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);
    
    return 0;
}