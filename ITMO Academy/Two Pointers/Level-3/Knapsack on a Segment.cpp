// Knapsack on a Segment (https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/E)
 
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
typedef long long ll;
 
void solve(vector<ll>& weights, vector<ll>& costs, int N, ll S) {
    ll curr_weight = 0, curr_cost = 0;
    ll max_cost = INT_MIN;
    int j = 0;
    for (int i = 0; i < N; i++) {
        curr_weight += weights[i];
        curr_cost += costs[i];

        while (j <= i && curr_weight > S) {
            curr_weight -= weights[j];
            curr_cost -= costs[j];
            j++;
        }

        max_cost = max(max_cost, curr_cost);
    }

    cout << max_cost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; ll S;
    cin >> N >> S;

    vector<ll> weights(N);
    for (int i = 0; i < N; i++)
        cin >> weights[i];

    vector<ll> costs(N);
    for (int i = 0; i < N; i++)
        cin >> costs[i];

    solve(weights, costs, N, S);
    
    return 0;
}