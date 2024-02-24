// Che city (https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/C)
 
#include <iostream>
#include <vector>
 
using namespace std;

// Time: O(NlogN)
// Space: O(1)

typedef long long ll;
 
void solve(vector<int>& A, int N, int R) {
    ll ways = 0;
    for (int i = 0; i < N; i++) {
        auto itr = upper_bound(A.begin(), A.end(), A[i]+R);
        if (itr != A.end())
            ways += A.end() - itr;
    }

    cout << ways << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, R;
    cin >> N >> R;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, R);
    
    return 0;
}