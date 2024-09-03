// Gravity Flip (https://codeforces.com/problemset/problem/405/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)

/**
 * Maximum height for any block will be 100.
 * 
 * Can use Counting Sort here for linear time sorting.
 */
 
const int MAX_N = 100 + 1;

void solve(vector<int>& A, int N) {
    vector<int> cnt(MAX_N, 0);
    for (int a : A)
        cnt[a]++; 

    for (int i = 0; i < MAX_N; i++) {
        while (cnt[i] > 0) {
            cout << i << " ";
            cnt[i]--;
        }
    }
    cout << endl;
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