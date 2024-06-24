// Longest Common Substring (https://codeforces.com/edu/course/2/lesson/2/5/practice/contest/269656/problem/B)
 
#include <iostream>
#include <vector>

using namespace std;
 
// Time: O(NlogN)
// Space: O(N)

vector<int> SA, LCP;

// lcp[i] => longest common prefix between SA[i] & SA[i+1]
void build_lcp_table(string& S) {
    int N = S.length();
    vector<int> rank(N, 0);
    for (int i = 0; i < N; i++)
        rank[SA[i]] = i;

    int k = 0;
    LCP.assign(N-1, 0);
    for (int i = 0; i < N; i++) {
        if (rank[i] == N-1) {
            k = 0;
            continue;
        }
        int j = SA[rank[i] + 1];
        while (i + k < N && j + k < N && S[i+k] == S[j+k])
            k++;
        LCP[rank[i]] = k;
        if (k)
            k--;
    }
}

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

int suffix_class(int suff_idx, int N) {
    return suff_idx < N ? 0 : 1;
}

void solve(string& S, string& T) {
    int N = S.length(), M = T.length();
    
    string str = S + '#' + T + '$';
    build_suffix_array(str);
    build_lcp_table(str);

    int max_len = 0, max_suff_idx = -1;
    int SA_N = SA.size();
    for (int i = 1; i < SA_N; i++) {
        if (suffix_class(SA[i-1], N) != suffix_class(SA[i], N)) {
            if (max_len < LCP[i-1]) {
                max_len = LCP[i-1];
                max_suff_idx = SA[i-1];
            }
        }
    }

    for (int i = 0; i < max_len; i++)
        cout << str[max_suff_idx+i];
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S, T;
    cin >> S >> T;

    solve(S, T);
    
    return 0;
}