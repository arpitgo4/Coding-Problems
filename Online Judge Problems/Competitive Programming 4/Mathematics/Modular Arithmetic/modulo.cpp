// modulo (https://open.kattis.com/problems/modulo)
 
#include <iostream>
#include <vector>
#include <unordered_set>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(vector<int>& nums) {
    unordered_set<int> distinct_nums;
    int num_cnt = 10;
    for (int num : nums) {
        distinct_nums.insert(num % 42);
    }

    cout << distinct_nums.size() << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> nums(10);
    for (int i = 0; i < 10; i++) {
        cin >> nums[i];
    }
    
    solve(nums);

    return 0;
}