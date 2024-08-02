// Equal Candies (https://codeforces.com/problemset/problem/1676/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)

typedef long long ll;
 
void solve(vector<int>& A, int N) {
    int min_e = *min_element(A.begin(), A.end());
    ll count = 0;
    for (int a : A)
        count += max(0, a-min_e);

    cout << count << endl;
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