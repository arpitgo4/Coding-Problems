// Number of Smaller (https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)

void solve(vector<int>& A, vector<int>& B, int N, int M) {
    int i = 0;
    for (int j = 0; j < M; j++) {
        while (i < N && A[i] < B[j]) {
            i++;
        }

        cout << (i) << " ";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> B(M);
    for (int i = 0; i < M; i++)
        cin >> B[i];

    solve(A, B, N, M);
    
    return 0;
}