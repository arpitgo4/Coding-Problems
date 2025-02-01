// tildes (https://open.kattis.com/problems/tildes)
 
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
 
using namespace std;
 
// Time: O(⍺(N))
// Space: O(N)
 
const int MAX_GUESTS = 1e6;

class DisjointSet {
public:
    DisjointSet(int set_sz) {
        parent_.assign(set_sz+1, -1);
        iota(parent_.begin(), parent_.end(), 0);
        sz_.assign(set_sz+1, 1);
    }

    int root(int x) {
        if (parent_[x] != x)
            parent_[x] = root(parent_[x]);

        return parent_[x];
    }

    void unionSet(int x, int y) {
        int root_x = root(x);
        int root_y = root(y);
        if (root_x != root_y) {
            if (sz_[root_x] < sz_[root_y])
                swap(root_x, root_y);

            parent_[root_y] = root_x;
            sz_[root_x] += sz_[root_y];
        }
    }

    int getSetSize(int x) {
        return sz_[root(x)];
    }

private:
    vector<int> parent_, sz_;
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int guest_cnt, query_cnt;
    cin >> guest_cnt >> query_cnt;
    
    DisjointSet ds(MAX_GUESTS);

    char type;
    int a, b;
    for (int i = 0; i < query_cnt; i++) {
        cin >> type >> a;
        if (type == 't') {
            cin >> b;
            ds.unionSet(a, b);
        } else if (type == 's') {
            cout << ds.getSetSize(a) << endl;
        }
    }
    
    return 0;
}