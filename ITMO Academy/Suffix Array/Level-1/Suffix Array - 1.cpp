// Suffix Array - 1 (https://codeforces.com/edu/course/2/lesson/2/1/practice/contest/269100/problem/A)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
/**
 * P[i] => represents suffix (starting index for substring[i..N])
 * C[i] => represents equivalence class for the suffix index stored at ith location
 * C[P[i]] => represents equivalence class for the suffix, P[i]
 * 
 * C[P[i]] => Suffix.equivalence_class
 * 
 * With Object-oriented programming,
 * we go deeper into object properties with `.` notation and we go deeper into object
 * when our statement reads from left to right or outside in.
 * 
 * But, with Procedural programming,
 * we go deeper into supposed to be object by `[]` notation and we go deeper into object
 * when our statement reads from right to left or inside out.
*/

// Time: O(N(logN)^2)
// Space: O(N)

typedef pair<int,int> substring;

vector<int> P, C;

void sort_cyclic_shifts(string& S) {
    int N = S.length();
    P.assign(N, -1);

    auto comp1 = [&](const int a, const int b) {
        return S[a] < S[b];
    };
    for (int i = 0; i < N; i++)
        P[i] = i;
    sort(P.begin(), P.end(), comp1);
    
    C.assign(N, 0);
    int classes = 1;
    for (int i = 1; i < N; i++) {
        if (S[P[i]] != S[P[i-1]])
            classes++;
        C[P[i]] = classes-1;
    }
    
    for (int k = 1; k <= ceil(log2(N)); k++) {
        // sort suffixes
        auto comp2 = [&](const int a, const int b) {
            substring s1 = { a, (a+(1<<(k-1))) % N };
            substring s2 = { b, (b+(1<<(k-1))) % N };

            if (C[s1.first] == C[s2.first])
                return C[s1.second] < C[s2.second];
            return C[s1.first] < C[s2.first];
        };
        sort(P.begin(), P.end(), comp2);

        // re-assign equivalence classes
        int classes = 1;
        vector<int> new_C(N, -1);
        new_C[P[0]] = classes-1;
        for (int i = 1; i < N; i++) {
            substring s1 = { P[i], (P[i]+(1<<(k-1))) % N };
            substring s2 = { P[i-1], (P[i-1]+(1<<(k-1))) % N };

            if (C[s1.first] != C[s2.first] || C[s1.second] != C[s2.second])
                classes++;
            new_C[P[i]] = classes-1;
        }

        C = new_C;
    }
}

void solve(string& S) {
    string str = S + "$";
    sort_cyclic_shifts(str);
 
    for (int suff_idx : P)
        cout << suff_idx << " ";
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;

    solve(S);
    
    return 0;
}