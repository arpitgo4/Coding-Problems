// Eating Queries (https://codeforces.com/problemset/problem/1676/E)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN + QlogN)
// Space: O(N)
 
/**
 * Sort array in descending order and calculate
 * prefix sum of above array.
 * 
 * Execute `lower_bound` queries on the pref array
 * and calculate count of candies by index of 
 * array that we converge to.
 */

vector<int> pref;

int query(int q, int N) {
    if (pref[N-1] < q)
        return -1;

    int l = 0, h = N-1;
    while (l <= h) {
        int m = (h-l)/2 + l;
        if (pref[m] >= q) {
            h = m-1;
        } else {                                                // pref[m] < q
            l = m+1;
        }
    }

    return l+1;
}

void solve(vector<int>& A, int N) {
    sort(A.begin(), A.end(), [&](const int a, const int b) {
        return a > b;
    });

    pref.assign(N, 0);
    pref[0] = A[0];
    for (int i = 1; i < N; i++)
        pref[i] = pref[i-1] + A[i];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, Q;
        cin >> N >> Q;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N);

        int q;
        for (int i = 0; i < Q; i++) {
            cin >> q;

            int count = query(q, N);
            cout << count << endl;
        }
    }
    
    return 0;
}