// Segments with Small Set (https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E)
 
#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
using ll = long long;
 
// Time: O(N)
// Space: O(N)

void solve(vector<int>& A, int N, int K) {
    unordered_map<int,int> uMap;
    ll count = 0; int j = 0;
    for (int i = 0; i < N; i++) {
        uMap[A[i]]++;

        while (j <= i && uMap.size() > K) {
            if (uMap[A[j]] == 1)
                uMap.erase(A[j]);
            else uMap[A[j]]--;
            j++;
        }

        if (!uMap.empty() && uMap.size() <= K) {
            int wind_size = i-j+1;
            int new_segments = (wind_size-1) + 1;
            count += new_segments;
        }
    }

    cout << count;
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