// Again Twenty Five! (https://codeforces.com/problemset/problem/630/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N;
    cin >> N;

    if (N == 0)
        cout << 1 << endl;
    else if (N == 1)
        cout << 5 << endl;
    else cout << 25 << endl;
    
    return 0;
}