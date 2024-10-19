// Similar Pairs (https://codeforces.com/problemset/problem/1360/C)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
void solve(vector<int>& A, int N) {
    int odd_cnt = 0;
    for (int a : A)
        if (a % 2 == 1)
            odd_cnt++;

    int even_cnt = N - odd_cnt;

    if (even_cnt % 2 == 0) {
        cout << "YES" << endl;
        return;
    }

    sort(A.begin(), A.end());

    bool found = false;
    for (int i = 0; i < N; i++) {
        auto itr = lower_bound(A.begin()+i+1, A.end(), A[i]);
        if (itr != A.end() && abs(A[i]-*itr) == 1) {
            found = true;
            break;
        }
    }

    cout << (found ? "YES" : "NO") << endl;
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