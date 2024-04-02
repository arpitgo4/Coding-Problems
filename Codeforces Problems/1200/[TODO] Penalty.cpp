// Penalty (https://codeforces.com/problemset/problem/1553/C)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
vector<int> dp;

int dfs(int i, int score1, int score2, string& S, int N) {
    if (i == N) {
        
    }
        
    
    
    int min_kicks = 0;
    if (i % 2 == 0) {                               // i % 2 == 0 (team A) else (team B)
        int goal = dfs(i+1, score1+1, score2, S, N); 
        int not_goal = dfs(i+1, score1, score2, S, N);

        if (S[i] == '1')
            min_kicks = goal 
        else if (S[i] == '0')
            min_kicks = not_goal;
        else min_kicks = min(goal, not_goal);
    } else {
        int goal = dfs(i+1, score1, score2+1, S, N); 
        int not_goal = dfs(i+1, score1, score2, S, N);

        if (S[i] == '1')
            min_kicks = goal 
        else if (S[i] == '0')
            min_kicks = not_goal;
        else min_kicks = min(goal, not_goal);
    }

    return min_kicks;
}

void solve(string& S) {
    int N = 10;
    dp.assign(N, -1);

    int min_kicks = dfs(0, S, N);
    cout << min_kicks;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    string S;
    while (T--) {
        cin >> S;

        solve(S);
    }   
    
    return 0;
}