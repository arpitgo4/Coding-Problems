// Following the String (https://codeforces.com/contest/1927/problem/B)
 
#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
typedef long long ll;
 
// Time: O(26^N)
// Space: O(N)
 
string S;
unordered_map<char,int> uMap;

bool dfs(int i, vector<int>& A, int N) {
    if (i == N)
        return true;

    if (A[i] == 0) {
        char c = 'a';
        for (int j = 0; j < 26; j++, c++) {
            if (uMap.find(c) == uMap.end()) {
                uMap[c]++;
                S.push_back(c);

                bool res = dfs(i+1, A, N);
                if (res) 
                    return true;

                S.pop_back();
                uMap[c] == 1 ? uMap.erase(c) : uMap[c]--;
            }
        }
    } else {
        for (auto& p : uMap) {
            if (p.second == A[i]) {
                char c = p.first;
                uMap[c]++;
                S.push_back(c);

                bool res = dfs(i+1, A, N);
                if (res) 
                    return true;

                S.pop_back();
                uMap[c] == 1 ? uMap.erase(c) : uMap[c]--;
            }
        }
    }

    return false;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    int N;
    while (T--) {
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        uMap.clear();
        S = "";
        dfs(0, A, N);

        cout << S << endl;
    }   
    
    return 0;
}