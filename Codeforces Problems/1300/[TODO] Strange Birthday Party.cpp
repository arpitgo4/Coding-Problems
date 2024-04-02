// Strange Birthday Party (https://codeforces.com/problemset/problem/1470/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
void solve(vector<int>& friends, int N, vector<int>& prices, int M) {
      
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> friends(N);
        for (int i = 0; i < N; i++)
            cin >> friends[i];

        vector<int> prices(M);
        for (int i = 0; i < M; i++)
            cin >> prices[i];

        solve(friends, N, prices, M);
    }
    
    return 0;
}