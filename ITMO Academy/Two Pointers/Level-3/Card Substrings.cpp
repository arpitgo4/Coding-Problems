// Card Substrings (https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/F)
 
#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;

// Time: O(N)
// Space: O(1)
 
typedef long long ll;
 
void solve(string& S, int N, string& cards, int M) {
    unordered_map<char,int> uMap;
    for (char& c : cards)
        uMap[c]++;
    
    int j = 0; ll count = 0;
    for (int i = 0; i < N; i++) {
        char c = S[i];

        while (j <= i && uMap.find(c) == uMap.end()) {
            uMap[S[j]]++;
            j++;
        }

        if (uMap.find(c) != uMap.end())
            uMap[c] == 1 ? uMap.erase(c) : uMap[c]--;

        int str_len = i-j+1;
        count += str_len;
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    string S, cards;
    cin >> S >> cards;

    solve(S, N, cards, M);
    
    return 0;
}