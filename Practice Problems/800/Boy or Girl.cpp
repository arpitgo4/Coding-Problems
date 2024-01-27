// Boy or Girl (https://codeforces.com/problemset/problem/236/A)

#include <iostream>

using namespace std;

// Time: O(N)
// Space: O(1)

void solve(string& username) {
    vector<int> v_set(26, 0);
    int dist_count = 0;
    for (char c : username) {
        int idx = c - 'a';
        if (v_set[idx] == 0) {
            v_set[idx] = 1;
            dist_count++;
        }
    }

    if (dist_count % 2 == 1) 
        cout << "IGNORE HIM!";
    else cout << "CHAT WITH HER!";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string username;
    cin >> username;

    solve(username);

    return 0;
}