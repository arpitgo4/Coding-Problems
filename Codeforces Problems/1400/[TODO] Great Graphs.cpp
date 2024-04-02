// Great Graphs (https://codeforces.com/problemset/problem/1540/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
#define INF LLONG_MAX
 
typedef long long ll;
 
// Time: O()
// Space: O()
 
void solve(vector<ll>& dist, int N) {
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<ll> dist(N);
        for (int i = 0; i < N; i++)
            cin >> dist[i];

        solve(dist, N);
    }

    return 0;
}