// Bogosort (https://codeforces.com/problemset/problem/1312/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O()
// Space: O()
 
/**
 * pair of indices in array (i,j) such that, (i < j)
 * Condition: (j - A[j] != i - A[i])
 * 
 * i - A[i] + A[j] != j
 * 
 * Brute-force approach,
 * 1. Generate all the permutations of the given array
 * 2. Test each permutation to be good
 * 
 * Time: O(N! * N^2)
 * Space: O(N)
 * 
 * Efficient approach,
 * 
 */

void solve(vector<int>& A, int N) {
    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; i++) {

        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
    
        solve(A, N);
    }
    
    return 0;
}