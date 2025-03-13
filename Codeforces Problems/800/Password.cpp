// Password (https://codeforces.com/problemset/problem/1743/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

const int MAX_SET_SIZE = 10;

int factorial(int num, vector<int>& dp) {
    if (num == 0)
        return 1;
    if (dp[num] != -1)
        return dp[num];
    return dp[num] = num * factorial(num-1, dp);
}

int choose(int set_size, int pick_cnt, vector<int>& dp) {
    int numer = (6 * factorial(set_size, dp));
    int denom = (factorial(pick_cnt, dp) * factorial(set_size-pick_cnt, dp));
    return  numer / denom;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_cnt;
    cin >> test_cnt;

    vector<int> dp(MAX_SET_SIZE+1, -1);
    dp[0] = 1;
    
    while (test_cnt > 0) {
        int discard_digit_cnt;
        cin >> discard_digit_cnt;

        int _;
        for (int i = 0; i < discard_digit_cnt; i++) {
            cin >> _;
        }

        int rem_digit_cnt = 10 - discard_digit_cnt;

        cout << choose(rem_digit_cnt, 2, dp) << endl;

        test_cnt--;
    }
    
    return 0;
}