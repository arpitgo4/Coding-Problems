// Children Holiday (https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
void solve(vector<tuple<int,int,int>>& A, int N, int M) {
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M, N;
    cin >> M >> N;

    vector<tuple<int,int,int>> A(N);
    int t, z, y;
    for (int i = 0; i < N; i++) {
        cin >> t >> z >> y;
        A[i] = { t, z, y };
    }

    solve(A, N, M);
    
    return 0;
}