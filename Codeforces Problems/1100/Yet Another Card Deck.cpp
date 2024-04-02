// Yet Another Card Deck (https://codeforces.com/problemset/problem/1511/C)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O()
// Space: O()
 
void solve(vector<int>& colors, int N, int q) {
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    vector<int> colors(N);
    for (int i = 0; i < N; i++)
        cin >> colors[i];

    int q;
    for (int i = 0; i < Q; i++) {
        cin >> q;
        solve(colors, N, q);
    }
    
    return 0;
}