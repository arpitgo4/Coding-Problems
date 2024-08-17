// Team Olympiad (https://codeforces.com/problemset/problem/490/A)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

void solve(vector<int>& A, int N) {
    unordered_map<int,vector<int>> uMap;
    for (int i = 0; i < N; i++) {
        if (uMap.find(A[i]) == uMap.end())
            uMap[A[i]] = *new vector<int>();

        uMap[A[i]].push_back(i+1);
    }

    int team_count = min(uMap[1].size(), min(uMap[2].size(), uMap[3].size()));

    cout << team_count << endl;
    for (int i = 0; i < team_count; i++) {
        cout << uMap[1].back() << " " << uMap[2].back() << " " << uMap[3].back() << endl;
        uMap[1].pop_back();
        uMap[2].pop_back();
        uMap[3].pop_back();
    }
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