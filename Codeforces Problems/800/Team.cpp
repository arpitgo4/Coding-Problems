// Team (https://codeforces.com/problemset/problem/231/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(vector<vector<int>>& A, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < 3; j++)
            if (A[i][j] == 1)
                cnt++;

        if (cnt >= 2)
            count++;
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<vector<int>> A(N, vector<int>(3));
    for (int i = 0; i < N; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    solve(A, N);
    
    return 0;
}