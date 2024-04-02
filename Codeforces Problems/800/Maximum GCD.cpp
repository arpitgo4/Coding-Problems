// Maximum GCD (https://codeforces.com/problemset/problem/1370/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
/**
 * Let the maximum gcd be equal to g. Since the two numbers in a pair are distinct, one of them must be >g and both of them must be divisible by g. The smallest multiple of g, greater than g, is 2*g. Since each number in the pair must be <=n, we must have 2*g <= n, or g <= floor(n2). We can achieve g=floor(n2), by choosing floor(n2) and 2*floor(n2).
*/
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        cout << (N/2) << endl;
    }

    return 0;
}