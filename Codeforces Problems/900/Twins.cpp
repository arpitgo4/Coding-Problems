// Twins (https://codeforces.com/problemset/problem/160/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
  
void solve(vector<int>& A, int N) {
    int total = 0;
    for (int a : A)
        total += a;

    sort(A.begin(), A.end());

    int sum = 0, count = 0;
    for (int i = N-1; i >= 0 && 2*sum <= total; i--) {
        sum += A[i];
        count++;
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);
    
    return 0;
}