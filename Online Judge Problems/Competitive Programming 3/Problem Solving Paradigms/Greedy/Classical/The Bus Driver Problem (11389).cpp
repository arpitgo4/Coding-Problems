// The Bus Driver Problem (11389)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)

void solve(vector<int>& M, vector<int>& E, int N, int D, int R) {
    sort(M.begin(), M.end());
    sort(E.begin(), E.end(), [&](const int a, const int b) {
        return a > b;
    });

    int extra_hours = 0;
    for (int i = 0; i < N; i++) {
        int total_time = M[i] + E[i];
        if (total_time > D)
            extra_hours += total_time - D;
    }

    cout << (extra_hours * R) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, D, R;
    cin >> N >> D >> R;

    while (N != 0 && D != 0 && R != 0) {
        vector<int> M(N);
        for (int i = 0; i < N; i++)
            cin >> M[i];

        vector<int> E(N);
        for (int i = 0; i < N; i++)
            cin >> E[i];

        solve(M, E, N, D, R);

        cin >> N >> D >> R;
    }
    
    return 0;
}