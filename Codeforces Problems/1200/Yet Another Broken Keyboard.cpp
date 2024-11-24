// Yet Another Broken Keyboard (https://codeforces.com/problemset/problem/1272/C)
 
#include <iostream>
#include <vector>
#include <unordered_set>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
/**
 * Can we use Two-pointers technique here to
 * find valid substring windows in the given 
 * string.
 * For each window, based on the length of window
 * calculate all substrings within it.
 * 
 * #substring = (N*(N+1))/2
 */

typedef long long ll;

void solve(string& S, vector<char>& A, int N, int K) {
    unordered_set<char> uSet(A.begin(), A.end());

    ll count = 0;
    int j = 0;
    for (int i = 0; i <= N; i++) {
        if (i == N || uSet.find(S[i]) == uSet.end()) {
            if (i != j) {
                ll w_sz = (i-1)-j+1;
                count += (w_sz * (w_sz+1)) / 2;
            }

            j = i+1;
        }
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;
    
    vector<char> A(K);
    for (int i = 0; i < K; i++)
        cin >> A[i];

    solve(S, A, N, K);
    
    return 0;
}