// Negatives and Positives (https://codeforces.com/problemset/problem/1791/E)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
 
using namespace std;

// Time: O(N)
// Space: O(1)

#define INF INT_MAX

typedef long long ll;

void solve(vector<int>& A, int N) {
    ll sum = 0;
    int neg_cnt = 0, min_num = INF;
    for (int a : A) {
        if (a < 0)
            neg_cnt++;

        sum += abs(a);
        min_num = min(min_num, abs(a));
    }

    if (neg_cnt % 2 == 0) {
        cout << sum << endl;
    } else {
        cout << (sum - 2 * min_num) << endl;
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