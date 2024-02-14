// Get together (https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A)
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;

// Time: O(NlogMAX_ITER) ~ O(N)
// Space: O(1)

const int MAX_ITER = 100;

bool if_segments_intersect(double l1, double h1, double l2, double h2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(h1, h2);
    }

    bool l2_within_bounds = (l2 >= l1 && l2 <= h1);
    bool h2_within_bounds = (h2 >= l1 && h2 <= h1);

    return l2_within_bounds || h2_within_bounds;
}

bool can_gather(double t, vector<double>& curr, vector<double>& speed, int N) {
    double l = INT_MIN, h = INT_MAX;
    for (int i = 0; i < N; i++) {
        double li = curr[i] - t * speed[i];
        double hi = curr[i] + t * speed[i];

        // check if segments intersect
        if (!if_segments_intersect(l, h, li, hi))
            return false;

        // find intersection
        l = fmax(l, li);
        h = fmin(h, hi);
    }

    return true;
}

void solve(vector<double>& curr, vector<double>& speed, int N) {
    double l = 0, h = 1e18;                 // lower and upper bounds for time
    for (int i = 0; i < MAX_ITER; i++) {
        double time = (h+l)/2;
        if (can_gather(time, curr, speed, N))
            h = time;
        else l = time;
    }

    cout << setprecision(15);
    cout << h << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<double> X(N), V(N);
    for (int i = 0; i < N; i++)
        cin >> X[i] >> V[i];
    
    solve(X, V, N);

    return 0;
}