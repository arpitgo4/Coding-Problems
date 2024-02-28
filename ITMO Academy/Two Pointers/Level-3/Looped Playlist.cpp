// Looped Playlist (https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;

// Time: O()
// Space: O()
 
void solve(vector<int>& A, int N, ll P) {
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    ll P;
    cin >> N >> P;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, P);  
    
    return 0;
}