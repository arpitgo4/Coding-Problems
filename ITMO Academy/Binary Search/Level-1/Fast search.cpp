// Fast search (https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)   [one time pre-processing]
// Time per query: O(logN)
// Space: O(1)

int upper_bound(vector<int>& A, int K) {
    int N = A.size();
    int l = 0, h = N-1;
    while (l <= h) {
        int m = (h-l)/2 + l;
        if (A[m] <= K)
            l = m+1;
        else h = m-1;               // A[m] > K
    }

    return l;
}

int lower_bound(vector<int>& A, int K) {
    int N = A.size();
    int l = 0, h = N-1;
    while (l <= h) {
        int m = (h-l)/2 + l;
        if (A[m] < K)
            l = m+1;
        else h = m-1;           // A[m] >= K
    }

    return l;
}

int solve(vector<int>& A, int l, int r) {
    int N = A.size();

    int i = lower_bound(A, l);
    int j = upper_bound(A, r)-1;

    if (i == N && j == N)
        return 0;
    if (j == N)
        return (N-1)-i+1;
    if (A[j] < l)                   // behind [l,r]
        return 0;
    if (A[i] > r)                   // after [l,r]
        return 0;

    return j-i+1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    int Q;
    cin >> Q;

    int l, r;
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        cout << solve(A, l, r) << " ";
    }
    
    return 0;
}