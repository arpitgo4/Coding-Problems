// Interesting Sum (https://codeforces.com/problemset/problem/1720/B)
 
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;

typedef long long ll;

#define INF INT_MAX
#define NEG_INF INT_MIN
 
// Time: O(N)
// Space: O(1)

// equation: (max_1 + max_2) - (min_1 + min_2)

void solve(vector<ll>& A, int N) {
    ll max_1 = NEG_INF, max_2 = NEG_INF, min_1 = INF, min_2 = INF;
    for (ll a : A) {
        if (a > max_1) {
            max_2 = max_1;
            max_1 = a;
        } else if (a > max_2)
            max_2 = a;

        if (a < min_1) {
            min_2 = min_1;
            min_1 = a;
        } else if (a < min_2)
            min_2 = a;
    }

    ll max_val = (max_1 + max_2) - (min_1 + min_2);
    cout << max_val << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<ll> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N);
    }
    
    return 0;
}