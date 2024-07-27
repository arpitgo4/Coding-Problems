// Oath of the Night's Watch (https://codeforces.com/problemset/problem/768/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(vector<int>& A, int N) {
    int min_e = *min_element(A.begin(), A.end());
    int max_e = *max_element(A.begin(), A.end());

    int count = 0;
    for (int i = 0; i < N; i++)
        if (A[i] > min_e && A[i] < max_e)
            count++;

    cout << count << endl;
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