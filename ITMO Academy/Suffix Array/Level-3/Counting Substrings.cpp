// Counting Substrings (https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(NlogN + MlogN)
// Space: O(N)

vector<int> SA;

void build_suffix_array(string& S) {
    const int ALPHABET = 256;
    int N = S.length();
    SA.assign(N, 0);
    vector<int> cnt(max(ALPHABET, N), 0);
    for (int i = 0; i < N; i++)
        cnt[S[i]]++;
    for (int i = 1; i < ALPHABET; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < N; i++)
        SA[--cnt[S[i]]] = i;

    vector<int> C(N, 0);
    C[SA[0]] = 0;
    int classes = 1;
    for (int i = 1; i < N; i++) {
        if (S[SA[i]] != S[SA[i-1]])
            classes++;
        C[SA[i]] = classes - 1;
    }

    vector<int> SAN(N), CN(N);
    for (int h = 0; (1 << h) < N; ++h) {
        for (int i = 0; i < N; i++) {
            SAN[i] = SA[i] - (1 << h);
            if (SAN[i] < 0)
                SAN[i] += N;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < N; i++)
            cnt[C[SAN[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = N-1; i >= 0; i--)
            SA[--cnt[C[SAN[i]]]] = SAN[i];
        CN[SA[0]] = 0;
        classes = 1;
        for (int i = 1; i < N; i++) {
            pair<int, int> cur = {C[SA[i]], C[(SA[i] + (1 << h)) % N]};
            pair<int, int> prev = {C[SA[i-1]], C[(SA[i-1] + (1 << h)) % N]};
            if (cur.first != prev.first || cur.second != prev.second)
                ++classes;
            CN[SA[i]] = classes - 1;
        }
        C = CN;
    }
}

int compare_suffix(int suff_idx, string& T, string& PAT) {
    int pat_len = PAT.length();
    for (int i = 0; i < pat_len; i++) {
        if (T[suff_idx+i] < PAT[i])
            return -1;
        if (T[suff_idx+i] > PAT[i])
            return 1;
    }

    return 0;
}

int lower_bound(string& T, string& PAT) {
    int l = 0, h = SA.size()-1;
    while (l <= h) {
        int m = (h-l)/2 + l;
        int comp = compare_suffix(SA[m], T, PAT);
        if (comp == -1)
            l = m+1;
        else if (comp == 1 || comp == 0)
            h = m-1;
    }

    return l;
}

int upper_bound(string& T, string& PAT) {
    int l = 0, h = SA.size()-1;
    while (l <= h) {
        int m = (h-l)/2 + l;
        int comp = compare_suffix(SA[m], T, PAT);
        if (comp == -1 || comp == 0)
            l = m+1;
        else if (comp == 1)
            h = m-1;
    }

    return h;
}

int count_substring(string& T, string& PAT) {
    int l = lower_bound(T, PAT);
    int h = upper_bound(T, PAT);
    return h-l+1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string T, PAT;
    cin >> T;

    T = T + '$';
    build_suffix_array(T);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> PAT;
        cout << count_substring(T, PAT) << endl;
    }
    
    return 0;
}