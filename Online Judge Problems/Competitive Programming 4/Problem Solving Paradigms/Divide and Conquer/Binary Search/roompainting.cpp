// roompainting (https://open.kattis.com/problems/roompainting)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int available_can_cnt, required_can_cnt;
    cin >> available_can_cnt >> required_can_cnt;

    vector<int> available_cans(available_can_cnt);
    for (int i = 0; i < available_can_cnt; i++) {
        cin >> available_cans[i];
    }

    sort(available_cans.begin(), available_cans.end());

    ll total_required = 0, total_bought = 0;
    int required_can;
    for (int i = 0; i < required_can_cnt; i++) {
        cin >> required_can;
        total_required += required_can;
        auto itr = lower_bound(available_cans.begin(), available_cans.end(), required_can);
        total_bought += *itr;
    }

    cout << (total_bought - total_required) << endl;
    
    return 0;
}