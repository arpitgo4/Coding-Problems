// Total Length (https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)

typedef long long ll;

void solve(vector<ll>& A, int N, ll S) {
    ll sum_length = 0, seg_sum = 0;
    int j = 0;
    for (int i = 0; i < N; i++) {
        // good segment if, (seg_sum <= S)
        seg_sum += A[i];

        while (j <= i && seg_sum > S) {
            seg_sum -= A[j];
            j++;
        }

        ll w_size = i-j+1;
        sum_length += (w_size * (w_size+1)) / 2;
    }

    cout << sum_length << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; ll S;
    cin >> N >> S;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, S);
    
    return 0;
}