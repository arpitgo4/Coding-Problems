// perket (https://open.kattis.com/problems/perket)
 
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
 
using namespace std;
 
// Time: O(2^N)
// Space: O(1)

const int INF = INT_MAX;

void solve(vector<int>& sourness, vector<int>& bitterness, int ing_cnt) {
    int min_diff = INF;

    for (int mask = 1; mask < (1 << ing_cnt); mask++) {
        int sourness_total = 1, bitterness_total = 0;
        for (int j = 0; j < ing_cnt; j++) {
            if (mask & (1 << j)) {
                sourness_total *= sourness[j];
                bitterness_total += bitterness[j];
            }
        }

        min_diff = min(min_diff, abs(sourness_total - bitterness_total));
    }

    cout << min_diff << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ing_cnt;
    cin >> ing_cnt;
    
    vector<int> sourness(ing_cnt), bitterness(ing_cnt);
    for (int i = 0; i < ing_cnt; i++) {
        cin >> sourness[i] >> bitterness[i];    
    }

    solve(sourness, bitterness, ing_cnt);
    
    return 0;
}