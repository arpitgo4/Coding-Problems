// Laptops (https://codeforces.com/problemset/problem/456/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
/**
 * Naive two-nested loop search can solve the problem but will be slow,
 * Time: O(N^2)
 * Space: O(1)
 * 
 * Sorting and Binary Searching is the way to optimize here!
 * 
 * Approach
 * 1. Sort by prices first
 */

void solve(vector<int>& A, vector<int>& B, int N) {
    vector<pair<int,int>> C(N);
    for (int i = 0; i < N; i++)
        C[i] = { A[i], B[i] };

    sort(C.begin(), C.end());

    for (int i = 0; i < N-1; i++) {
        if (C[i].second > C[i+1].second) {
            cout << "Happy Alex" << endl;
            return;
        }
    }

    cout << "Poor Alex" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];

    solve(A, B, N);
    
    return 0;
}