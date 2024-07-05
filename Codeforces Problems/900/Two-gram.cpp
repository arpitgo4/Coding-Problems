// Two-gram (https://codeforces.com/problemset/problem/977/B)
 
#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
void solve(string& S, int N) {
    unordered_map<string,int> uMap;
    string max_sub = "";
    int max_count = 0;
    for (int i = 1; i < N; i++) {
        string sub = S.substr(i-1, 2);
        if (uMap.find(sub) == uMap.end())
            uMap[sub] = 0;

        uMap[sub]++;

        if (uMap[sub] > max_count) {
            max_count = uMap[sub];
            max_sub = sub;
        }
    }

    cout << max_sub << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    string S;
    cin >> S;

    solve(S, N);
    
    return 0;
}