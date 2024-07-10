// Even Subset Sum Problem (https://codeforces.com/problemset/problem/1323/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(2^N)
// Space: O(N)

vector<int> dfs(int i, vector<int>& A, int N, int sum, vector<int>& subset) {
    if (i == N)
        return sum % 2 == 0 ? subset : *new vector<int>();
    
    subset.push_back(i);
    vector<int> a = dfs(i+1, A, N, sum+A[i], subset);
    if (a.size() > 0)
        return a;

    subset.pop_back();
    return dfs(i+1, A, N, sum, subset);
}

void solve(vector<int>& A, int N) {
    vector<int> subset = dfs(0, A, N, 0, *new vector<int>());

    if (subset.size() > 0) {
        cout << subset.size() << endl;
        for (int i : subset)
            cout << (i+1) << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N);
    }
    
    return 0;
}