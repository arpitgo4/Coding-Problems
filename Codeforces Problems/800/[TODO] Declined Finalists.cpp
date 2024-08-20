// Declined Finalists (https://codeforces.com/problemset/problem/859/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(KlogK)
// Space: O(1)
 
void solve(vector<int>& A, int K) {
    sort(A.begin(), A.end());

    int count = 0, next = K;
    for (int i = 1; i <= 25; i++) {
        auto itr_a = lower_bound(A.begin(), A.end(), i);
        if (*itr_a != i) {
            do {
                count++;
                next++;
                itr_a = lower_bound(A.begin(), A.end(), next);
                cout << next << endl;
            } while (*itr_a != next);
        }
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;
    
    vector<int> A(K);
    for (int i = 0; i < K; i++)
        cin >> A[i];

    solve(A, K);
    
    return 0;
}