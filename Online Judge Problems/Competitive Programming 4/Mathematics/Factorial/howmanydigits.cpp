// howmanydigits (https://open.kattis.com/problems/howmanydigits)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
const int MAX_X = 1e6;

double solve(int x, vector<double>& dp) {
    if (x == 0)
        return 0;
    if (dp[x] != -1)
        return dp[x];

    return dp[x] = log10(x) + solve(x-1, dp);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<double> dp(MAX_X+1, -1);

    int x;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);

        ss >> x;

        double cnt = solve(x, dp);
        cout << floor(cnt) + 1 << endl;
    }
    
    return 0;
}