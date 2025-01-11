// buttonbashing (https://open.kattis.com/problems/buttonbashing) 
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
 
using namespace std;
 
// Time: O(3600) ~ O(1)
// Space: O(3600) ~ O(1)
 
#define INF INT_MAX

const int MIN_TIME = 0;
const int MAX_TIME = 3600;

int minBtnPresses(vector<int>& btns, int btn_cnt, int target_time, vector<int>& dist) {
    vector<int> vis(MAX_TIME+1, 0);

    queue<int> state_queue;
    state_queue.push(0);
    vis[0] = 1;
    dist[0] = 0;

    int nearest_time = INF;

    while (!state_queue.empty()) {
        int curr = state_queue.front();
        state_queue.pop();

        if (vis[curr] == 2)
            continue;

        if (curr >= target_time) {
            nearest_time = min(nearest_time, curr);

            if (curr == target_time)
                return curr;
        }

        for (int btn : btns) {
            int next = curr + btn;
            next = max(MIN_TIME, min(next, MAX_TIME));

            if (vis[next] == 0) {
                state_queue.push(next);
                vis[next] = 1;
                dist[next] = dist[curr] + 1;
            }
        }

        vis[curr] = 2;
    }

    return nearest_time;
}

void solve(vector<int>& btns, int btn_cnt, int target_time) {
    vector<int> dist(MAX_TIME+1, INF);
    int nearest_time = minBtnPresses(btns, btn_cnt, target_time, dist);

    cout << dist[nearest_time] << " " << (nearest_time - target_time) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_cases_cnt;
    cin >> test_cases_cnt;
    
    while (test_cases_cnt--) {
        int btn_cnt, target_time;
        cin >> btn_cnt >> target_time;

        vector<int> btns(btn_cnt);
        for (int i = 0; i < btn_cnt; i++)
            cin >> btns[i];        

        solve(btns, btn_cnt, target_time);
    }
    
    return 0;
}