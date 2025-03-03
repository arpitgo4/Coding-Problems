// forestfruits (https://open.kattis.com/problems/forestfruits)
 
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>
#include <cmath>
#include <numeric>
#include <set>
 
using namespace std;
 
// Time: O(ElogV + VlogV)
// Space: O(V)
 
using ll_t = long long;
using edge_t = tuple<int,int,ll_t>;
using graph_edge_t = pair<int,ll_t>;
using graph_t = vector<vector<graph_edge_t>>;
using queue_state_t = pair<ll_t,int>;

const int INF = INT_MAX;

void calculateShortestPathToClearings(
    graph_t& adj_list, 
    int src, 
    int clearing_cnt, 
    vector<ll_t>& dist,
    vector<int>& parent
) {
    vector<int> vis(clearing_cnt+1, 0);

    auto cmp = [&](const queue_state_t& s1, const queue_state_t& s2) {
        return s1.first > s2.first;
    };
    priority_queue<queue_state_t, vector<queue_state_t>, decltype(cmp)> pq(cmp);

    dist[src] = 0;
    pq.push({ dist[src], src });

    while (!pq.empty()) {
        auto [ _, curr ] = pq.top();
        pq.pop();

        if (vis[curr] != 0)
            continue;

        vis[curr] = 1;
        for (auto& [next, time_taken] : adj_list[curr]) {
            if (dist[next] > dist[curr] + time_taken) {
                dist[next] = dist[curr] + time_taken;
                pq.push({ dist[next], next });
                parent[next] = curr;
            }
        }

        vis[curr] = 2;
    }
}

void solve(
    int clearing_cnt, 
    vector<edge_t>& trails, 
    int trail_cnt, 
    vector<int>& clearings_with_fruits, 
    int clearing_with_fruits_cnt, 
    int restore_days_cnt, 
    int days_cnt
) {

    graph_t adj_list(clearing_cnt+1, vector<graph_edge_t>());
    for (auto& [from, to, time_taken] : trails) {
        adj_list[from].push_back({ to, time_taken });
        adj_list[to].push_back({ from, time_taken });
    }

    vector<ll_t> dist(clearing_cnt+1, INF);
    vector<int> parent(clearing_cnt+1, -1);
    iota(parent.begin(), parent.end(), 0);

    calculateShortestPathToClearings(adj_list, 1, clearing_cnt, dist, parent);

    multiset<ll_t> times_to_clearings;
    for (ll_t d : dist) {
        if (d != INF && d != 0) {
            times_to_clearings.insert(d);
        }
    }

    if (times_to_clearings.size() < restore_days_cnt) {
        cout << -1 << endl;
    } else {
        auto itr = times_to_clearings.begin();
        advance(itr, restore_days_cnt-1);

        cout << ((*itr) * 2) << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int clearing_cnt, trail_cnt, clearing_with_fruits_cnt, restore_days_cnt, days_cnt;
    cin >> clearing_cnt >> trail_cnt >> clearing_with_fruits_cnt >> restore_days_cnt >> days_cnt;

    int from, to; ll_t time_taken;
    vector<edge_t> trails(trail_cnt);
    for (int i = 0; i < trail_cnt; i++) {
        cin >> from >> to >> time_taken;
        trails[i] = { from, to, time_taken };
    }

    vector<int> clearings_with_fruits(clearing_with_fruits_cnt);
    for (int i = 0; i < clearing_with_fruits_cnt; i++) {
        cin >> clearings_with_fruits[i];
    }

    solve(
        clearing_cnt, 
        trails, 
        trail_cnt, 
        clearings_with_fruits, 
        clearing_with_fruits_cnt, 
        restore_days_cnt, 
        days_cnt
    );
    
    return 0;
}