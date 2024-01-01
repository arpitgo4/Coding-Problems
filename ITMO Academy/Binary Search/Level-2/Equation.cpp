// Equation (https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E)
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
 
using namespace std;

// Time: O(1)
// Space: O(1)
 
bool satisfies(double X, double C) {
    return (X*X) + sqrt(X) - C <= 1e-6;
}

void solve(double C) {
    double m;
    double l = 1.0, h = 1e11;
    for (int i = 0; i < 100; i++) {
        m = (h-l)/2 + l;
        if (satisfies(m, C))
            l = m+1e-6;
        else h = m-1e-6;         // > 1e-6
    }

    cout << setprecision(7);
    cout << m;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double C;
    cin >> C;

    solve(C);
    
    return 0;
}