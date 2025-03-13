// Hossam and Combinatorics (https://codeforces.com/problemset/problem/1771/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)

using ll_t = long long;

void solve(vector<int>& nums, ll_t num_cnt) {
    int max_num = *max_element(nums.begin(), nums.end());
    int min_num = *min_element(nums.begin(), nums.end());

    if (max_num == min_num) {
        cout << (num_cnt * (num_cnt-1) * 1LL) << endl;
        return;
    }

    ll_t max_num_cnt = 0, min_num_cnt = 0;
    for (int x : nums) {
        if (x == max_num) {
            max_num_cnt++;
        }
        if (x == min_num) {
            min_num_cnt++;
        }
    }

    cout << (max_num_cnt * min_num_cnt * 2LL) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_cnt;
    cin >> test_cnt;
    
    while (test_cnt > 0) {
        int num_cnt;
        cin >> num_cnt;

        vector<int> nums(num_cnt);
        for (int i = 0; i < num_cnt; i++) {
            cin >> nums[i];
        }

        solve(nums, num_cnt);

        test_cnt--;
    }
    
    return 0;
}