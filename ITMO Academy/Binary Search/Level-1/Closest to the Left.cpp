// Closest to the Left (https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B)
 
#include <iostream>
#include <vector>
 
using namespace std;

// Time: O(logN)
// Space: O(1)
 
int lower_bound_2(vector<int>& A, int K) {
    int N = A.size();
    int l = 0, h = N-1;
    while (h-l > 1) {
        int m = (h-l)/2 + l;
        if (A[m] <= K)
            l = m;
        else h = m-1;       // A[m] > K
    }

    if (A[h] <= K)
        return h+1;
    else if (A[l] <= K) 
        return l+1;
    else return l;              // if (A[l] > K) => return (l-1) + 1     // +1 to adjust to 1-based indexing rqeuired by the problem for output
}

int lower_bound(vector<int>& A, int K) {
    int N = A.size();
    int l = 0, h = N-1;
    while (l <= h) {
        int m = (h-l)/2 + l;
        if (A[m] <= K)
            l = m+1;
        else h = m-1;
    }

    return h+1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> res;
    int q;   
    for (int i = 0; i < Q; i++) {
        cin >> q;
        res.push_back(lower_bound_2(A, q));
    }

    for (int r : res)
        cout << r << endl;
    
    return 0;
}