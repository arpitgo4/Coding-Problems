// Remove Smallest (https://codeforces.com/problemset/problem/1399/A)
 
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iterator>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
void solve(vector<int>& A, int N) {
    multiset<int> mset(A.begin(), A.end());

    while (mset.size() > 1) {
        int a = *mset.begin();
        mset.erase(mset.begin());

        auto itr = mset.lower_bound(a);
        if (itr == mset.end())
            itr = prev(itr);

        int b = *itr;
        mset.erase(itr);
        if (abs(a-b) > 1) {
            cout << "NO" << endl;
            return;
        } else {
            mset.insert(max(a, b));
        }
    }

    cout << "YES" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N);
    }
    
    return 0;
}