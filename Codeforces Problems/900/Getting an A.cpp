// Getting an A (https://codeforces.com/problemset/problem/991/B)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
void solve(vector<int>& A, int N) {
    sort(A.begin(), A.end());

    double sum = 0;
    for (int a : A)
        sum += a;

    int count = 0;
    for (int i = 0; i < N && round(sum/N) < 5; i++) {
        sum -= A[i];
        sum += 5;
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