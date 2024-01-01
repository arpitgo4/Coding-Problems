// Bear and Big Brother

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Binary Search Implementation ???
// Time: O(logN) ~ O(log7) ~ O(1)
// Space: O(1)
// max value for N = 7

// let's find upper bounds for search space
// a = 1, b = 10
// a = [1, 3, 9, 27, 81, 243, 729]
// b = [10, 20, 40, 80, 160, 320, 640]
// after 7 years a will take over b

// max search space: [1, 2, 3, 4, 5, 6, 7]
// find the least value where a > b
// both a & b creates a GP with r = 3 & 2 respectively
// nth term for a GP = ar^(n-1)

void solve(int a, int b) {
    int l = 1, h = 7;
    while (l <= h) {
        int m = (h-l)/2 + l;
        int n_a = a * pow(3, m-1);
        int n_b = b * pow(2, m-1);

        if (n_a > n_b) {
            h = m-1;
        } else {    // n_a <= n_b
            l = m+1;
        }
    }    

    cout << (l-1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    solve(a, b);

    return 0;
}