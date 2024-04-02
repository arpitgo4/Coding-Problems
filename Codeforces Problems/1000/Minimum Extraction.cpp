// Minimum Extraction (https://codeforces.com/problemset/problem/1607/C)
 
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
 
using namespace std;
 
typedef long long ll;
 
// Time: O(N + NlogN)
// Space: O(N)
 
void solve(vector<int>& A, int N) {
    auto comp = [&](const int a, const int b) {
        return a > b;
    };
    priority_queue<int, vector<int>, decltype(comp)> pq(A.begin(), A.end(), comp);      // min-heap

    ll max_min = INT_MIN;
    ll total_sub = 0;
    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();
        
        max_min = max(max_min, a - total_sub);
        total_sub += (a - total_sub);
    }

    cout << max_min << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N);
    }   
    
    return 0;
}