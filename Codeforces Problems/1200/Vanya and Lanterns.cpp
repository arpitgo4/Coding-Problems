// Vanya and Lanterns (https://codeforces.com/problemset/problem/492/B)
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
/**
 * We can use binary search the answer here.
 * As after a certain limit for radius, every value
 * can be the answer. We need to find the lower_bound
 * of this range.
 * 
 * Light radius can be seen as a segment and the verification
 * function can be used to confirm that each segment from the 
 * lamp overlaps or is adjacent to the previous and next one.
 */

bool check(double r, vector<double>& A, int N, int L) {
    bool can_cover = true;
    for (int i = 1; i < N && can_cover; i++) {
        if (A[i-1] == A[i])
            continue;
        if (A[i-1]+r < A[i]-r)
            can_cover = false;
    }

    return can_cover && A[N-1]+r >= L && A[0]-r <= 0;
}

void solve(vector<double>& A, int N, int L) {
    sort(A.begin(), A.end());

    double l = 0, h = 1e9;
    for (int i = 0; i < 200; i++) {
        double m = (h-l)/2 + l;
        if (check(m, A, N, L))
            h = m-1e-9;
        else l = m+1e-9;
    }

    cout << setprecision(9) << l << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;
    
    vector<double> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, L);
    
    return 0;
}