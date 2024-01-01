// Student Councils (https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G)
 
#include <iostream>
#include <vector>
 
using namespace std;

// K <= N (number of student groups)
// K => council size
// N => number of student groups
// Ai => size of each student group

// no two students from same group should be in same council
// council should have students from different groups

void solve(vector<int>& A, int N, int K) {
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K, N;
    cin >> K >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, K);
    
    return 0;
}