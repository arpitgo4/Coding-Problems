// Scarecrow (12405)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)

int solve(vector<int>& A, int N) {
    int count = 0;
    for (int i = 1; i <= N;) {    
        if (A[i-1] == 1) {
            count++;
            i += 3;
        } else {
            i++;
        }
    }

    return count;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, idx = 0;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        char c;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> c;
            if (c == '.')
                A[i] = 1;
            else A[i] = -1;
        }

        int count = solve(A, N);
        cout << "Case " << (++idx) << ": " << count << endl;
    }
    
    return 0;
}