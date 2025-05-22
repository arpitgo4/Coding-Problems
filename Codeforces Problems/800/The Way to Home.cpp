// The Way to Home (https://codeforces.com/problemset/problem/910/A)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(vector<int>& line, int dest, int max_jump_len) {
    if (line[dest] == 1 && line[1] == 0) {
        cout << -1 << endl;
        return;
    }
    if (dest == 1) {
        cout << 0 << endl;
        return;
    }

    int jmp_cnt = 0;
    int curr_pos = 1;
    while (curr_pos != dest) {
        bool lily_found = false;
        int next_pos = curr_pos + max_jump_len;

        if (next_pos > dest) {
            jmp_cnt++;
            break;
        }

        while (next_pos != curr_pos) {
            if (line[next_pos] == 1) {
                curr_pos = next_pos;
                lily_found = true;
                jmp_cnt++;
                break;
            }
            next_pos--;
        }

        if (!lily_found) {
            jmp_cnt = -1;
            break;
        }
    }

    cout << jmp_cnt << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int dest, max_jump_len;
    cin >> dest >> max_jump_len;
    
    string str_line;
    cin >> str_line;

    vector<int> line(dest+1, 0);
    for (int i = 0; i < str_line.length(); i++) {
        if (str_line[i] == '1')
            line[i+1] = 1;
    }

    solve(line, dest, max_jump_len);
    
    return 0;
}