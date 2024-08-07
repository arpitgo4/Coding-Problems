// GamingForces (https://codeforces.com/problemset/problem/1792/A)
 
#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
void solve(vector<int>& A, int N) {
    multiset<int> mSet(A.begin(), A.end());

    int count = 0;
    while (mSet.size() > 1) {
        auto itr_1 = mSet.begin();
        int a = *itr_1;
        mSet.erase(itr_1);

        auto itr_2 = mSet.lower_bound(a);
        int b = *itr_2;
        mSet.erase(itr_2);

        if (a == 1 && b == 1)
            count++;
        else {
            count++;
            mSet.insert(b);
        }
    }

    if (!mSet.empty())
        count++;

    cout << count << endl;
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