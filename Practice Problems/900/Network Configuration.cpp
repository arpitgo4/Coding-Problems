// Network Configuration (https://codeforces.com/problemset/problem/412/B)
 
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
 
using namespace std;
 
// Time: O(N + NlogN)
// Space: O(N)
 
void solve(vector<int>& A, int N, int K) {
    auto comp = [&](const int a, const int b) {
        return a > b;
    };
    priority_queue<int, vector<int>, decltype(comp)> pq(A.begin(), A.end(), comp);      // min-heap

    int max_speed = INT_MIN;
    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();

        if ((pq.size()+1) >= K)
            max_speed = max(max_speed, a);
    }

    cout << max_speed;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, K);
    
    return 0;
}