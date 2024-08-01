// Gas Stations (12321)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)

/**
 * TODO: find better interval search method
 * Consider the problem as starting from [0,0] interval
 * and try reaching [??,L] interval
 * 
 * If possible, count number of intervals needed
*/

/*
40 3 
5 5 
20 10 
40 10

40 5 
5 5 
11 8 
20 10 
30 3 
40 10

40 5 
0 10 
10 10 
20 10 
30 10 
40 10

40 3
10 10 
18 10 
25 10

40 3 
10 10 
18 10 
25 15
*/ 

typedef pair<int,int> interval;

bool is_non_overlapping(auto& p1, auto& p2) {
    int l = p1.first, h = p1.second;

    return (p2.first > h || p2.second < l);
}

bool is_fully_overlapping(auto& p1, auto& p2) {
    int l = p1.first, h = p1.second;

    bool c1 = (l <= p2.first && p2.first <= h);
    bool c2 = (l <= p2.second && p2.second <= h);

    return c1 && c2;
}

int binary_search(vector<interval>& S, int N, int val) {
    int l = 0, h = N-1;
    while (l <= h) {
        int m = (h-l)/2 + l;
        if (S[m].first == val)
            return m;
        else if (S[m].first > val)
            h = m-1;
        else l = m+1;
    }

    return -1;
}

int solve(int L, vector<int>& X, vector<int>& R, int N) {
    vector<interval> S(N);
    for (int i = 0; i < N; i++)
        S[i] = { X[i]-R[i], X[i]+R[i] };

    sort(S.begin(), S.end(), [&](const interval& p1, const interval& p2) {
        if (p1.first == p2.first)
            return p2.second > p2.second;
        return p1.first < p2.first;
    });

    interval curr = { 0, 0 };
    int count = 0;
    int i = 0;
    while (curr.second < L) {
        int idx = binary_search(S, N, curr.second);
        cout << "found: " << S[idx].first << ", " << S[idx].second << endl;
        if (idx == -1) {
            count++;
            curr = S[i+1];
        }
        else if (S[idx].first > curr.second)
            return -1;
        else {
            count++;
            curr = S[idx];
            i = idx;
        }
    }

    return N-count;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int L, N;
    cin >> L >> N;

    while (L != 0 && N != 0) {
        vector<int> X(N), R(N);
        for (int i = 0; i < N; i++)
            cin >> X[i] >> R[i];

        int count = solve(L, X, R, N);
        cout << count << endl;

        cin >> L >> N;
    }
    
    return 0;
}