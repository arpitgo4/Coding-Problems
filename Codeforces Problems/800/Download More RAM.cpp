// Download More RAM (https://codeforces.com/problemset/problem/1629/A)
 
#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
void solve(vector<int>& A, vector<int>& B, int N, int K) {
    vector<int> idx(N, -1);
    for (int i = 0; i < N; i++)
        idx[i] = i;

    auto comp = [&](const int a, const int b) {
        return A[a] > A[b];
    };
    priority_queue<int, vector<int>, decltype(comp)> pq(idx.begin(), idx.end(), comp);      // min-heap

    int count = K;
    while (!pq.empty()) {
        int i = pq.top();
        pq.pop();

        int a = A[i], b = B[i];
        if (a > count)
            break;
        
        count += b;
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        for (int i = 0; i < N; i++)
            cin >> B[i];
    
        solve(A, B, N, K);
    }
    
    return 0;
}