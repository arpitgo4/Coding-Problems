// Mystic Permutation (https://codeforces.com/problemset/problem/1689/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
 
using namespace std;

// Time: O(NlogN)
// Space: O(N)
 
/**
 * Only last two places can break the condition, 
 *  P[N-1] != Q[N-1] AND P[N] != Q[N]
 * 
 * Rest all positions can be filled with smallest number 
 * available from the set.
 * 
 * Conflict for last 2 places can be solved in O(1) time,
 * it can either be (a, b) OR (b, a)
 */

vector<int> idx, acc;
set<int> uSet;

bool dfs(int i, vector<int>& P, int N) {
    if (i == N)
        return true;
    if (uSet.size() == 1) {
        int p = *uSet.begin();
        if (idx[p] == i)
            return false;
    }

    auto choice_a = uSet.begin();
    auto choice_b = next(choice_a);
    if (idx[*choice_a] == i)
        swap(choice_a, choice_b);

    acc[i] = *choice_a;
    uSet.erase(choice_a);
    bool found = dfs(i+1, P, N);
    if (found)
        return true;

    uSet.insert(acc[i]);
    acc[i] = *choice_b;
    uSet.erase(choice_b);

    return dfs(i+1, P, N);
}

void solve(vector<int>& P, int N) {
    acc.assign(N, -1);
    idx.assign(N, -1);
    for (int i = 0; i < N; i++) {
        idx[P[i]] = i;
        uSet.insert(P[i]);
    }

    bool found = dfs(0, P, N);

    if (!found) {
        cout << -1 << endl;
    } else {
        for (int p : acc)
            cout << p << " ";
        cout << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> P(N);
        for (int i = 0; i < N; i++)
            cin >> P[i];

        solve(P, N);
    }
    
    return 0;
}