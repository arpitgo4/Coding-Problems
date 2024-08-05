// Angry Monk (https://codeforces.com/problemset/problem/1992/B)
 
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
void solve(vector<int>& A, int K, int N) {
    multiset<int> mSet(A.begin(), A.end());

    int count = 0;
    while (mSet.size() > 1) {
        auto min_pc_itr = mSet.begin();
        auto max_pc_itr = prev(mSet.end());

        int min_pc = *min_pc_itr;
        int max_pc = *max_pc_itr;

        mSet.insert(max_pc + min_pc);
        count += (2 * (min_pc-1)) + 1;
        
        mSet.erase(min_pc_itr);
        mSet.erase(max_pc_itr);
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(K);
        for (int i = 0; i < K; i++)
            cin >> A[i];
    
        solve(A, K, N);
    }
    
    return 0;
}