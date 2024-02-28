// Splitting an Array (https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
void solve(vector<int>& A, int N, int K) {
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, K);
    
    return 0;
}