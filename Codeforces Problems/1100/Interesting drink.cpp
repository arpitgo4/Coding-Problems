// Interesting drink (https://codeforces.com/problemset/problem/706/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
 
using namespace std;
 
// Time: O(NlogN + QlogN)
// Space: O(1)

void solve(vector<int>& prices, int N, vector<int>& spend_limit, int Q) {
    sort(prices.begin(), prices.end());

    for (int i = 0; i < Q; i++) {
        auto itr = upper_bound(prices.begin(), prices.end(), spend_limit[i]);
        cout << (prev(itr) - prices.begin() + 1) << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> prices(N);
    for (int i = 0; i < N; i++)
        cin >> prices[i];

    int Q;
    cin >> Q;

    vector<int> spend_limit(Q);
    for (int i = 0; i < Q; i++)
        cin >> spend_limit[i];

    solve(prices, N, spend_limit, Q);
    
    return 0;
}