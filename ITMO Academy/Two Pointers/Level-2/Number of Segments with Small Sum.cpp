// Number of Segments with Small Sum (https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/C)

#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
// Time: O(N)
// Space: O(1)

void solve(vector<int>& A, int N, ll S) {
    int count = 0;
    ll curr_sum = 0;
    int j = 0;
    for (int i = 0; i < N; i++) {
        curr_sum += A[i];

        while (j <= i && curr_sum > S) {
            curr_sum -= A[j];
            j++;
        }

        if (curr_sum <= S)
            count++;
    }

    cout << count;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    ll S;
    cin >> N >> S;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, S);
    
    return 0;
}