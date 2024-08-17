// Even Array (https://codeforces.com/problemset/problem/1367/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(vector<int>& A, int N) {
    int bad_0 = 0, bad_1 = 0;
    for (int i = 0; i < N; i++) {
        int a = A[i];
        if (a % 2 != i % 2) {
            if (a % 2 == 0)
                bad_0++;
            else bad_1++;
        }
    }

    cout << (bad_0 == bad_1 ? bad_0 : -1) << endl;
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