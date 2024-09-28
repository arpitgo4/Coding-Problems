// New Bakery (https://codeforces.com/problemset/problem/1978/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O()
// Space: O()
 
// sum of first N natural numbers: n(n-1)/2;

int calc_profit(int N, int A, int B, int K) {
    // (k*B) - (1+2+---+(k-1)) + ((N-k) * a)
    // (K*B) + (N*K) - (K*A) - ((k-1)(k-2))/2
    // K(N+B-A) - (K^2 - 3K + 2)/2
}

void solve(int N, int A, int B) {
    int l = 0, h = min(N, B);
    while (l <= h) {
        int m = (h-l)/2 + l;
        if ()
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, A, B;
        cin >> N >> A >> B;
        
        solve(N, A, B);
    }
    
    return 0;
}