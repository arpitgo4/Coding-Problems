// Ilya and Queries (https://codeforces.com/problemset/problem/313/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
                                 
vector<int> pref;

int query(int l, int r) {
    if (l == 0)
        return pref[r-1];
    return pref[r-1] - pref[l-1];
}

void solve(string& S) {
    int N = S.length();

    vector<int> A(N, 0);
    for (int i = 0; i < N-1; i++)
        if (S[i] == S[i+1])
            A[i] = 1;

    pref.assign(N, 0);
    pref[0] = A[0];
    for (int i = 1; i < N; i++)
        pref[i] = pref[i-1] + A[i];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;

    solve(S);

    int Q;
    cin >> Q;
    
    int l, r;
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        int count = query(l-1, r-1);
        cout << count << endl;
    }
    
    return 0;
}