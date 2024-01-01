// Very Easy Task (https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C)

#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
using ll = long long;
 
// DOESN'T WORK....!!!
// Time: O(1)
// Space: O(1)
void solve_2(int N, double X, double Y) {
    ll time_first = min(X, Y);       // time for first copy
    N--;

    ll time_rest = ceil(N / ((1/X) + (1/Y)));

    cout << time_first + time_rest;
}

// Time: O(logN)
// Space: O(1)

bool can_copy(ll time, int N, double X, double Y) {
    double speed_x = 1/X;
    double speed_y = 1/Y;

    int count_x = (speed_x * time);
    int count_y = (speed_y * time);

    return count_x + count_y >= N;
}

void solve(int N, int X, int Y) {
    ll time_first = min(X, Y);       // time for first copy
    N--;

    ll l = 0, h = 1e9;
    while (l <= h) {
        ll m = (h-l)/2 + l;
        if (can_copy(m, N, X, Y))
            h = m-1;
        else l = m+1;
    }

    cout << (l + time_first);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, X, Y;
    cin >> N >> X >> Y;

    // solve(N, X, Y);
    solve_2(N, X, Y);
    
    return 0;
}