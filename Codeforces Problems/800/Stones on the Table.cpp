// Stones on the Table (https://codeforces.com/problemset/problem/266/A)

#include <iostream>

using namespace std;

// Time: O(N)
// Space: O(1)

void solve(string& A, int N) {
    int i = 1, j = 0;
    int count = 0;
    while (i < N) {
        if (A[i] == A[j])
            count++;
        else
            j = i;

        i++;
    }

    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string stones;
    cin >> N >> stones;

    solve(stones, N);

    return 0;
}