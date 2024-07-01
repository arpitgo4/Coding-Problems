// Love Triangle (https://codeforces.com/problemset/problem/939/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)

void solve(vector<int>& likes, int N) {
    bool love_triangle_found = false;

    for (int u = 1; u <= N; u++) 
        if (likes[likes[likes[u]]] == u)
            love_triangle_found = true;

    cout << (love_triangle_found ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> likes(N+1);
    for (int i = 1; i <= N; i++)
        cin >> likes[i];

    solve(likes, N);
    
    return 0;
}