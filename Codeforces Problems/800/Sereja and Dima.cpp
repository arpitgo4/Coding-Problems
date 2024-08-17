// Sereja and Dima (https://codeforces.com/problemset/problem/381/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O()
// Space: O()
 
void solve(vector<int>& A, int N) {
    int s_sum = 0, d_sum = 0;
    int j = 0, k = N-1, max_card = 0;
    for (int i = 0; i < N; i++) {
        if (A[j] > A[k]) {
            max_card = A[j];
            j++;
        } else {
            max_card = A[k];
            k--;
        }

        if (i % 2 == 0)
            s_sum += max_card;
        else d_sum += max_card;
    }

    cout << s_sum << " " << d_sum << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);
    
    return 0;
}