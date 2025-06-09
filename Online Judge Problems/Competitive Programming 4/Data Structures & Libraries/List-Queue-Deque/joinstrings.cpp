// joinstrings (https://open.kattis.com/problems/joinstrings)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
void printStrings(
    vector<vector<int>>& adj_list,
    vector<string>& strs,
    int curr_idx
) {
    cout << strs[curr_idx];
    for (int next_idx : adj_list[curr_idx]) {
        printStrings(adj_list, strs, next_idx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int str_cnt;
    cin >> str_cnt;

    vector<string> strs(str_cnt);
    for (int i = 0; i < str_cnt; i++) {
        cin >> strs[i];
    }

    vector<vector<int>> adj_list(str_cnt+1, vector<int>());
    int a, b;
    int last_str_idx = 0;
    for (int i = 0; i < str_cnt-1; i++) {
        cin >> a >> b;
        a--;
        b--;
        adj_list[a].push_back(b);
        last_str_idx = a;
    }

    printStrings(adj_list, strs, last_str_idx);
    cout << endl;
    
    return 0;
}