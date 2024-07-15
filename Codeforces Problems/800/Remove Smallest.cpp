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
    multiset<int> mSet(A.begin(), A.end());

    while (mSet.size() > 1) {
        int a = *mSet.begin();
        mSet.erase(mSet.begin());

        auto itr = mSet.lower_bound(a);
        if (itr == mSet.end())
            itr = prev(itr);

        int b = *itr;
        mSet.erase(itr);
        if (abs(a-b) > 1) {
            cout << "NO" << endl;
            return;
        } else {
            mSet.insert(max(a, b));
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