// Team Composition: Programmers and Mathematicians (https://codeforces.com/problemset/problem/1611/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
// Time: O(T * logN)
// Space: O(1)
 
bool can_form_teams(int team_size, int a, int b) {
    a -= team_size;
    b -= team_size;

    return a >= 0 && b >= 0 && (a+b) >= (2*team_size);
}

void solve(int a, int b) {
    int l = 1, h = 1e9;
    while (l <= h) {
        int m = (h-l)/2 + l;
        if (can_form_teams(m, a, b))
            l = m+1;
        else h = m-1;
    }
    
    cout << h << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    int a, b;
    while (T--) {
        cin >> a >> b;

        solve(a, b);
    }   
    
    return 0;
}