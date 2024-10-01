// Showering (https://codeforces.com/problemset/problem/1999/C)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
typedef pair<int,int> interval;

bool does_overlap(interval& p1, interval& p2) {
    if (p1.first > p2.first)
        swap(p1, p2);

    return !(p1.second <= p2.first);
}

void solve(vector<interval>& A, int N, int S, int M) {
    bool can_shower = false;
    int timer = 0;
    for (int i = 0; i < N; i++) {
        interval curr = { timer, timer+S };
        if (!does_overlap(curr, A[i]))
            can_shower = true;
        else timer = A[i].second;
    }

    interval curr = { timer, timer+S };
    interval end = { M, M };
    if (!does_overlap(curr, end))
        can_shower = true;

    cout << (can_shower ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, S, M;
        cin >> N >> S >> M;
        
        int l, r;
        vector<interval> A(N);
        for (int i = 0; i < N; i++) {
            cin >> l >> r;
            A[i] = { l, r };
        }
    
        solve(A, N, S, M);
    }
    
    return 0;
}