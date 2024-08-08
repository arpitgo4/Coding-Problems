// I Wanna Be the Guy (https://codeforces.com/problemset/problem/469/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
const int MAX_N = 100;

void solve(int N, vector<int>& X, int P, vector<int>& Y, int Q) {
    vector<bool> table(MAX_N+1, false);
    for (int a : X)
        table[a] = true;
    for (int a : Y)
        table[a] = true;

    int i = 1;
    for (; i <= N && table[i] == true; i++);

    cout << (i > N ? "I become the guy." : "Oh, my keyboard!") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int P, Q;
    cin >> P;

    vector<int> X(P);
    for (int i = 0; i < P; i++)
        cin >> X[i];

    cin >> Q;
    vector<int> Y(Q);
    for (int i = 0; i < Q; i++)
        cin >> Y[i];

    solve(N, X, P, Y, Q);
    
    return 0;
}