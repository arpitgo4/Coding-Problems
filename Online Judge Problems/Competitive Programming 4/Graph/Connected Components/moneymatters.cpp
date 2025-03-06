// moneymatters (https://open.kattis.com/problems/moneymatters)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)
 
using edge_t = pair<int,int>;
using graph_t = vector<vector<int>>;

int calculateTotalOweForConnectedComponent(
    int curr_friend,
    graph_t& adj_list,
    vector<int>& owes,
    vector<int>& vis
) {

    vis[curr_friend] = 1;

    int total = owes[curr_friend];
    for (int next_friend : adj_list[curr_friend]) {
        if (vis[next_friend] == 0) {
            total += calculateTotalOweForConnectedComponent(
                next_friend,
                adj_list,
                owes,
                vis
            );
        }
    }

    return total;
}

void solve(
    vector<int>& owes, 
    int friend_cnt, 
    vector<edge_t>& friendships, 
    int friendship_cnt
) {
 
    graph_t adj_list(friend_cnt, vector<int>());
    for (auto& [from, to] : friendships) {
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }

    bool can_split_even = true;
    vector<int> vis(friend_cnt, 0);
    for (int i = 0; i < friend_cnt; i++) {
        if (vis[i] == 0) {
            int total_owe = calculateTotalOweForConnectedComponent(
                i,
                adj_list,
                owes,
                vis
            );

            if (total_owe != 0) {
                can_split_even = false;
                break;
            }
        }
    }

    cout << (can_split_even ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int friend_cnt, friendship_cnt;
    cin >> friend_cnt >> friendship_cnt;
    
    vector<int> owes(friend_cnt);
    for (int i = 0; i < friend_cnt; i++) {
        cin >> owes[i];    
    }

    int f1, f2;
    vector<edge_t> friendships(friendship_cnt);
    for (int i = 0; i < friendship_cnt; i++) {
        cin >> f1 >> f2;
        friendships[i] = { f1, f2 };
    }

    solve(owes, friend_cnt, friendships, friendship_cnt);
    
    return 0;
}