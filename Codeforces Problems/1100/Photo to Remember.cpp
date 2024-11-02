// Photo to Remember (https://codeforces.com/problemset/problem/522/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)

void solve(vector<pair<int,int>>& A, int N) {
    int tot_w = 0;
    int max_1 = 0, max_2 = 0;
    for (int i = 0; i < N; i++) {
        tot_w += A[i].first;
        if (A[i].second > max_1) {
            max_2 = max_1;
            max_1 = A[i].second;
        } else if (A[i].second > max_2)
            max_2 = A[i].second;
    }

    for (int i = 0; i < N; i++) {
        int min_w = tot_w - A[i].first;
        int max_h = (A[i].second == max_1 ? max_2 : max_1);

        cout << (min_w * max_h) << " ";
    }
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int w, h;
    vector<pair<int,int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> w >> h;
        A[i] = { w, h };
    }

    solve(A, N);
    
    return 0;
}
