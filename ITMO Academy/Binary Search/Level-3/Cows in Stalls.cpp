// Cows in Stalls (https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/C)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// M = 1e9
// Time: O(NlogNlogM)
// Space: O(1)

bool can_arrange(int m, vector<int>& stalls, int N, int K) {
    int curr = 0;
    for (int i = 1; i < K; i++) {
        int next = stalls[curr] + m;
        auto itr = lower_bound(stalls.begin(), stalls.end(), next);
        if (itr == stalls.end())
            return false;

        curr = itr-stalls.begin();
    }

    return true;
}

void solve(int N, vector<int>& stalls, int K) {
    int l = 1, h = 1e9;
    while (l <= h) {
        int m = (h-l)/2 + l;
        if (can_arrange(m, stalls, N, K))
            l = m+1;
        else h = m-1;
    }

    cout << h << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    vector<int> stalls(N);
    for (int i = 0; i < N; i++)
        cin >> stalls[i];

    solve(N, stalls, K);
    
    return 0;
}