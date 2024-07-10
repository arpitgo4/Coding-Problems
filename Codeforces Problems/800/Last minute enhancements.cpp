// Last minute enhancements (https://codeforces.com/problemset/problem/1466/B)
 
#include <iostream>
#include <vector>
#include <unordered_set>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

void solve(vector<int>& A, int N) {
    unordered_set<int> uSet;
    for (int a : A) {
        if (uSet.find(a) == uSet.end())
            uSet.insert(a);
        else if (uSet.find(a+1) == uSet.end())
            uSet.insert(a+1);
    }

    cout << uSet.size() << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N);
    }
    
    return 0;
}