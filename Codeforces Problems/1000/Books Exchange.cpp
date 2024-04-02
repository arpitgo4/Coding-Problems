// Books Exchange (https://codeforces.com/problemset/problem/1249/B1)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O()
// Space: O()
 
vector<int> P, S;
 
void solve(vector<int>& A, int N) {
    P.assign(N+1, -1);
    S.assign(N+1, 1);
    for (int i = 0; i < N+1; i++)
        P[i] = i;

    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Q;
    cin >> Q;

    while (Q--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N);
    }
    
    return 0;
}