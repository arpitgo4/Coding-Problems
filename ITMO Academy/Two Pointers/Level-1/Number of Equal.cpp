// Number of Equal (https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B)

#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
// Time: O(N)
// Space: O(1)

void solve(vector<int>& A, vector<int>& B, int N, int M) {
    ll count = 0, prev_count = 0;
    int i = 0, j = 0;
    for (int k = 0; k < M; k++) {
        if (k > 0 && B[k-1] == B[k]) {
            count += prev_count;
            continue;
        }

        if (i < N && A[i] < B[k]) {
            while (i < N && A[i] < B[k])
                i++;
            j = i;
        }

        while (i < N && A[i] == B[k])
            i++;
        
        prev_count = i-j;
        count += (i-j);
        j = i;
    }

    cout << count;
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