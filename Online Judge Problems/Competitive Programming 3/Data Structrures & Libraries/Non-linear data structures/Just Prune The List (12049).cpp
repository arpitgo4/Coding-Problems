// Just Prune The List (12049)
 
#include <iostream>
#include <vector>
#include <set>
 
using namespace std;

// Time: O(NlogN)
// Space: O(N)
 
void solve(vector<int>& A, int N, vector<int>& B, int M) {
    multiset<int> om_set(A.begin(), A.end());

    int count = 0;
    for (int b : B) {
        if (om_set.find(b) == om_set.end())
            count++;
        else om_set.erase(om_set.find(b));
    }

    om_set.clear();
    for (int b : B)
        om_set.insert(b);

    for (int a : A) {
        if (om_set.find(a) == om_set.end())
            count++;
        else om_set.erase(om_set.find(a));
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N), B(M);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        for (int i = 0; i < M; i++)
            cin >> B[i];

        solve(A, N, B, M);
    } 
    
    return 0;
}