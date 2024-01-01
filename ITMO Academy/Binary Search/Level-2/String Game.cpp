// String Game (https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F)
 
#include <iostream>
#include <vector>
#include <unordered_set>
 
using namespace std;

// Time: O(N + NlogN)
// Space: O(N)

bool can_form_string(int m, string& T, string& P, vector<int>& A, unordered_set<int>& uSet) {
    int N = T.length(), M = P.length();
    int j = 0;
    for (int i = 0; i < N && j < M; i++) {
        if (uSet.find(i) != uSet.end())
            continue;

        if (T[i] == P[j])
            j++;
    }

    return j == M;
}

void solve(string& T, string& P, vector<int>& A) {
    int N = A.size();
    int l = 0, h = N-1, m;
    unordered_set<int> uSet;
    while (l <= h) {
        m = (h-l)/2 + l;

        int last_idx = uSet.size() - 1;
        if (m > last_idx) {
            int curr_idx = last_idx + 1;
            while (curr_idx <= m)
                uSet.insert(A[curr_idx++]-1);
        } else {                                    // m <= last_idx
            int curr_idx = last_idx;
            while (curr_idx > m)
                uSet.erase(A[curr_idx--]-1);
        }

        if (can_form_string(m, T, P, A, uSet))
            l = m+1;
        else 
            h = m-1;
    }

    cout << (h+1);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string T, P;
    cin >> T >> P;

    int N = T.length();
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(T, P, A);
    
    return 0;
}