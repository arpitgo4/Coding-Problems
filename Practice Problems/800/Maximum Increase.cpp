// Maximum Increase (https://codeforces.com/problemset/problem/702/A)

#include <iostream>
#include <vector>
 
using namespace std;

// Time: O(N)
// Space: O(1)

void solve(vector<int>& A, int N) {
    int max_wind = 1;
    int j = 0;
    for (int i = 1; i < N; i++) {
        if (A[i-1] >= A[i]) {
            while (j < i)
                j++;
        }

        max_wind = max(max_wind, i-j+1);
    }

    cout << max_wind;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);
    
    return 0;
}