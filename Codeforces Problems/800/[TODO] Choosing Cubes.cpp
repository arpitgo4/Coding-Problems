// Choosing Cubes (https://codeforces.com/problemset/problem/1980/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
void solve(vector<int>& A, int N, int F, int K) {
    sort(A.begin(), A.end());

    int f_val = A[F-1];
    auto l_itr = lower_bound(A.begin(), A.end(), f_val);
    auto u_itr = upper_bound(A.begin(), A.end(), f_val);

    int l = l_itr - A.begin();
    int h = u_itr - A.begin();

    cout << l << ", " << h << endl;

    int remaining = N-h;
    int fav_count = (h-1)-l+1;

    cout << remaining << ", " << fav_count << endl;

    if (K <= remaining)
        cout << "NO" << endl;
    else if (K >= (fav_count+remaining))
        cout << "YES" << endl;
    else cout << "MAYBE" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, F, K;
        cin >> N >> F >> K;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
    
        solve(A, N, F, K);
    }
    
    return 0;
}