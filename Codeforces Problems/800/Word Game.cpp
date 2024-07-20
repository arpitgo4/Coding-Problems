// Word Game (https://codeforces.com/problemset/problem/1722/C)
 
#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
void solve(vector<vector<string>>& S, int N) {
    vector<int> score(3, 0);
    unordered_map<string,int> dict;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++) {
            if (dict.find(S[i][j]) == dict.end())
                dict.insert({ S[i][j], 0 });
            
            dict[S[i][j]]++;
        }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++) {
            int count = dict[S[i][j]];
            if (count == 1) {
                score[i] += 3;
            } else if (count == 2) {
                score[i] += 1;
            }
        }

    cout << score[0] << " " << score[1] << " " << score[2] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<vector<string>> S(3, vector<string>(N));
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < N; j++) {
                cin >> S[i][j];
            }

        solve(S, N);
    }
    
    return 0;
}