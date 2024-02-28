// Cows in Stalls (https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/C)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
void solve(int N, vector<int>& stalls, int K) {
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    vector<int> stalls(N);
    for (int i = 0; i < N; i++)
        cin >> stalls[i];

    solve(N, stalls, K);
    
    return 0;
}