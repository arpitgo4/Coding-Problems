// Hotelier (https://codeforces.com/problemset/problem/1200/A)
 
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <cctype>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
const int MAX_ROOMS = 10;

void solve(string& S, int N) {
    set<int> uSet;
    for (int i = 0; i < MAX_ROOMS; i++)
        uSet.insert(i);

    vector<int> bSet(MAX_ROOMS, 0);
    for (char c : S) {
        if (isdigit(c)) {
            int num = c - '0';
            bSet[num] = 0;
            uSet.insert(num);
        } else {
            auto itr = (c == 'L' ? uSet.begin() : prev(uSet.end()));
            bSet[*itr] = 1;
            uSet.erase(itr);
        }
    }

    for (int i = 0; i < MAX_ROOMS; i++)
        cout << bSet[i];
    cout << endl;
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