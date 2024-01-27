// Parking (https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/B)
 
#include <iostream>
#include <vector>
 
using namespace std;

// Time: O(⍺(N))
// Space: O(N)
 
// Available slot is the one which is the root of the tree
// Un-available slot is pointing to either root or other non-empty slot

vector<int> P;

void init(int N) {
    P.assign(N+1, -1);
    for (int i = 0; i < N+1; i++)
        P[i] = i;
}

// find with path compression
int find_slot(int x) {
    if (P[x] != x)
        P[x] = find_slot(P[x]);
    
    return P[x];
}

void remove_slot(int x, int N) {
    int q = (x+1) % (N+1);
    if (q == 0)
        q = 1;

    int y = find_slot(q);
    P[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    init(N);

    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        int slot = find_slot(x);
        remove_slot(slot, N);
        cout << slot << " ";
    }
     
    return 0;
}