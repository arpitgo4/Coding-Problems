// CD (11849)
 
#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)

void solve(vector<int>& A, int N, vector<int>& B, int M) {
    set<int> o_set(A.begin(), A.end());

    int count = 0;
    for (int b : B) {
        if (o_set.find(b) != o_set.end()) {
            count++;
            o_set.erase(o_set.find(b));
        }
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    while (N != 0 && M != 0) {
        vector<int> A(N), B(M);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        for (int i = 0; i < M; i++)
            cin >> B[i];

        solve(A, N, B, M);

        cin >> N >> M;
    }   
    
    return 0;
}