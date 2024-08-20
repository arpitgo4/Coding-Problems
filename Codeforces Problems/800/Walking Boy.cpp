// Walking Boy (https://codeforces.com/problemset/problem/1776/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(vector<int>& A, int N) {
    int count = 0, time = 0;
    
    A.push_back(1440);
    for (int a : A) {
        int diff = a - time;
        count += (diff / 120);

        time = a;
    }

    cout << (count >= 2 ? "YES" : "NO") << endl;
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