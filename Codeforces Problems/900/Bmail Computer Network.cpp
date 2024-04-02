// Bmail Computer Network (https://codeforces.com/problemset/problem/1057/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
// Time: O(N)
// Space: O(N)
 
vector<int> P;

void solve(int u) {
    vector<int> path;
    do {
        path.push_back(u);
        u = P[u];
    } while (u != -1);

    reverse(path.begin(), path.end());

    for (int u : path)
        cout << u << " ";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int p;
    P.assign(N+1, -1);
    for (int i = 0; i < N-1; i++) {
        cin >> p;
        P[i+2] = p;
    }

    solve(N);
    
    return 0;
}