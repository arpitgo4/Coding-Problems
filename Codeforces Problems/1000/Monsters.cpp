// Monsters (https://codeforces.com/problemset/problem/1849/B)
 
#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
void solve(vector<int>& A, int N, int K) {
    auto cmp = [&](const auto& p1, const auto& p2) {
        if (p1.first == p2.first)
            return p1.second < p2.second;

        return p1.first > p2.first;
    };
    vector<int> order;
    set<pair<int,int>, decltype(cmp)> oSet(cmp);
    for (int i = 0; i < N; i++) {
        if (A[i] % K == 0)
            order.push_back(i);
        else oSet.insert({ A[i] % K, i });
    }

    while (!oSet.empty()) {
        auto [ h, i ] = *oSet.begin();
        oSet.erase(oSet.begin());

        if (h-K > 0)
            oSet.insert({ h-K, i });
        else order.push_back(i);
    }

    for (int i : order)
        cout << (i+1) << " ";
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
    
        solve(A, N, K);
    }
    
    return 0;
}