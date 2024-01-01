// Binary Search (https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A)

#include <iostream>
#include <vector>
 
using namespace std;

// Time: O(logN)
// Space: O(1)
 
int binary_search_2(vector<int>& A, int K) {
    int N = A.size();
    int l = 0, h = N-1;
    while (h-l > 1) {
        int m = (h-l)/2 + l;
        if (A[m] == K)
            return A[m];
        else if (A[m] < K)
            l = m+1;
        else h = m-1;
    }

    if (A[l] == K || A[h] == K)
        return K;
    else return -1;
}

int binary_search(vector<int>& A, int K) {
    int N = A.size();
    int l = 0, h = N-1;
    while (l <= h) {
        int m = (h-l)/2 + l;
        if (A[m] == K)
            return A[m];
        else if (A[m] < K)
            l = m+1;
        else h = m-1;
    }

    return -1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
        cin >> queries[i];

    for (int q : queries) {
        int res = binary_search_2(A, q);
        if (res == q)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}