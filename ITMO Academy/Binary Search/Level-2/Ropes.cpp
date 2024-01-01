// Ropes (https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B)
 
#include <iomanip>
#include <iostream>
#include <vector>
 
using namespace std;

// Time: O(Nlog(100)) ~ O(N)
// Space: O(1)
 
bool can_cut(double size, vector<double>& A, int K) {
    int counter = 0;
    for (double a : A)
        counter += a/size;

    return counter >= K;
}

void solve(vector<double>& A, int N, int K) {
    double l = 0, h = 1e7;
    double m = 0.0;
    for (int i = 0; i < 100; i++) {
        m = (h-l)/2 + l;

        if (can_cut(m, A, K))
            l = m;
        else h = m;
    }

    cout << setprecision(7);
    cout << h;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    vector<double> A(N);
    for (double& a : A)
        cin >> a;

    solve(A, N, K);

    return 0;
}