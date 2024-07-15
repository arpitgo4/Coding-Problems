// Block Towers (https://codeforces.com/problemset/problem/1767/B)
 
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
// t1 -> tower 1
// t2 -> tower 2
// diff = t2 - t1
// t1 + x = t2 - x
// t1 + 2x = t2
// x = (t2-t1)/2

// +1 when (t2-t1) % 2 == 1

void solve(vector<int>& A, int N) {
    multiset<int> mSet(next(A.begin()), A.end());

    int t1 = *A.begin();
    while (mSet.upper_bound(t1) != mSet.end()) {
        auto itr = mSet.upper_bound(t1);

        int t2 = *itr;
        int diff = (t2 - t1) / 2;
        if ((t2-t1) % 2 == 1)
            diff += 1;
            
        t1 += diff;

        mSet.erase(itr);
    }

    cout << t1 << endl;
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