// Number of Segments with Big Sum (https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/D)
 
#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

// Time: O(N)
// Space: O(1)

void solve(vector<int>& A, int N, ll S) {
    ll curr_sum = 0, count = 0;
    int j = 0;
    for (int i = 0; i < N; i++) {
        curr_sum += A[i];
        
        // shrink window from rear, every valid window can pair
        // with all number on the outside on right of the window
        // as input values are > 0
        while (j <= i && curr_sum >= S) {
            int new_segments = (N-1)-i+1;
            count += new_segments;
            curr_sum -= A[j];
            j++;
        }
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