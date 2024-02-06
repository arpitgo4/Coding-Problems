// New Year and Hurry (https://codeforces.com/problemset/problem/750/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(logN)
// Space: O(1)
 
int sum_AP(int a, int i, int d) {
    // s(i) = i/2 * (2a + (i-1)d)
    return (2 * a + (i-1) * d) * i / 2;
}

// each problem takes 5i time (1 <= i <= N)
// 5, 10, 15, 20, .....
// arithmetic progression
// can find the sum of first n terms in O(1)
// we can use binary search to find the number of 
// problems we can solve in `time_left`
void solve(int N, int K) {
    int time_left = 240 - K;
    
    int l = 1, h = N;
    while (l <= h) {
        int m = (h-l)/2 + l;
        if (sum_AP(5, m, 5) > time_left)
            h = m-1;
        else l = m+1;                       // sum_AP(1, m) <= time_left
    }

    cout << h;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    solve(N, K);   
    
    return 0;
}