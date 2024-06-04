// Substring Search (https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(NlogN + MlogN)
// Space: O(N)

vector<int> P, C;
const int ALPHABET = 256;

void build_suffix_array(string& S) {
    int N = S.length();
    P.assign(N, 0);
    C.assign(N, 0);
    vector<int> cnt(max(ALPHABET, N), 0);
    for (int i = 0; i < N; i++)
        cnt[S[i]]++;
    for (int i = 1; i < ALPHABET; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < N; i++)
        P[--cnt[S[i]]] = i;
    C[P[0]] = 0;
    int classes = 1;
    for (int i = 1; i < N; i++) {
        if (S[P[i]] != S[P[i-1]])
            classes++;
        C[P[i]] = classes - 1;
    }

    vector<int> PN(N), CN(N);
    for (int h = 0; (1 << h) < N; ++h) {
        for (int i = 0; i < N; i++) {
            PN[i] = P[i] - (1 << h);
            if (PN[i] < 0)
                PN[i] += N;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < N; i++)
            cnt[C[PN[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = N-1; i >= 0; i--)
            P[--cnt[C[PN[i]]]] = PN[i];
        CN[P[0]] = 0;
        classes = 1;
        for (int i = 1; i < N; i++) {
            pair<int, int> cur = {C[P[i]], C[(P[i] + (1 << h)) % N]};
            pair<int, int> prev = {C[P[i-1]], C[(P[i-1] + (1 << h)) % N]};
            if (cur.first != prev.first || cur.second != prev.second)
                ++classes;
            CN[P[i]] = classes - 1;
        }
        C = CN;
    }
}

int compare_suffix(int suff_idx, string& T, string& PAT) {
    int N = T.length();
    int pat_len = PAT.length();
    int suff_len = N - suff_idx;
    for (int i = 0; i < pat_len; i++) {
        if (T[suff_idx+i] < PAT[i])
            return -1;                              // Pattern > Suffix 
        if (T[suff_idx+i] > PAT[i])
            return 1;                              // Pattern < Suffix
    }

    return 0;
}

bool search(string& T, string& PAT) {
    int l = 0, h = P.size()-1;
    while (l <= h) {
        int m = (h-l)/2 + l;
        if (compare_suffix(P[m], T, PAT) == 0)
            return true;
        else if (compare_suffix(P[m], T, PAT) == -1)
            l = m+1;
        else h = m-1;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string T, P;
    cin >> T;

    T = T + '$';
    build_suffix_array(T);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> P;
        bool found = search(T, P);
        cout << (found ? "Yes" : "No") << endl;
    }
    
    return 0;
}