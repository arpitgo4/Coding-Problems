// Business trip (https://codeforces.com/problemset/problem/149/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(vector<int>& A, int K) {
    sort(A.begin(), A.end());

    int sum = 0, count = 0;
    for (int i = 11; i >= 0 && sum < K; i--) {   
        sum += A[i];
        count++;
    }

    if (sum < K)
        cout << -1 << endl;
    else cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K;
    cin >> K;

    vector<int> A(12);
    for (int i = 0; i < 12; i++)
        cin >> A[i];

    solve(A, K);
    
    return 0;
}