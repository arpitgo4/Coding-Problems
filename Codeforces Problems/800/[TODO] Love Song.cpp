// Love Song (https://codeforces.com/problemset/problem/1539/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O()
// Space: O()
 
void solve(string& S, int N, int l, int r) {
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    

    int l, r;
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        int len = solve(S, N, l, r);
        cout << len << endl;
    }
    
    return 0;
}