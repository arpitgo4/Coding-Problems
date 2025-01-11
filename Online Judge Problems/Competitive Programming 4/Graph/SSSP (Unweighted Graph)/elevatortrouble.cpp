// elevatortrouble (https://open.kattis.com/problems/elevatortrouble)
 
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)

#define INF INT_MAX

void minBtnPresses(int floor_cnt, int src_floor, int dest_floor, int up_cnt, int down_cnt, vector<int>& dist) {
    vector<int> vis(floor_cnt+1, 0);
    vector<int> moves{ up_cnt, -down_cnt };

    queue<int> floor_queue;
    floor_queue.push(src_floor);
    vis[src_floor] = 1;
    dist[src_floor] = 0;

    while (!floor_queue.empty()) {
        int curr = floor_queue.front();
        floor_queue.pop();

        if (vis[curr] == 2)
            continue;

        for (int move : moves) {
            int next = curr + move;

            if (next >= 1 && next <= floor_cnt && vis[next] == 0) {
                floor_queue.push(next);
                vis[next] = 1;
                dist[next] = dist[curr] + 1;
            }
        }
        
        vis[curr] = 2;
    }
}

void solve(int floor_cnt, int src_floor, int dest_floor, int up_cnt, int down_cnt) {
    vector<int> dist(floor_cnt+1, INF);

    minBtnPresses(floor_cnt, src_floor, dest_floor, up_cnt, down_cnt, dist);

    if (dist[dest_floor] == INF) {
        cout << "use the stairs" << endl;
    } else {
        cout << dist[dest_floor] << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int floor_cnt, src_floor, dest_floor, up_cnt, down_cnt;
    cin >> floor_cnt >> src_floor >> dest_floor >> up_cnt >> down_cnt;

    solve(floor_cnt, src_floor, dest_floor, up_cnt, down_cnt);
    
    return 0;
}