// unionfind (https://open.kattis.com/problems/unionfind)
 
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(Q * ⍺(N))
// Space: O(N)
 
class DisjointSet {
public:
    DisjointSet(int set_size) {
        parent_.assign(set_size+1, -1);
        iota(parent_.begin(), parent_.end(), 0);
        size_.assign(set_size+1, 1);
    }

    int root(int x) {
        if (parent_[x] != x)
            parent_[x] = root(parent_[x]);

        return parent_[x];
    }

    void union_set(int x, int y) {
        int root_x = root(x);
        int root_y = root(y);
        if (root_x != root_y) {
            if (size_[root_x] < size_[root_y])
                swap(root_x, root_y);

            parent_[root_y] = root_x;
            size_[root_x] += size_[root_y];
            size_[root_y] = -1;
        }
    }

private:
    vector<int> parent_, size_;
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int elem_cnt, op_cnt;
    cin >> elem_cnt >> op_cnt;
    
    DisjointSet ds(elem_cnt);

    char type;
    int a, b;
    for (int i = 0; i < op_cnt; i++) {
        cin >> type >> a >> b;
        if (type == '=') {
            ds.union_set(a, b);
        } else if (type == '?') {
            cout << (ds.root(a) == ds.root(b) ? "yes" : "no") << endl;
        }
    }
    
    return 0;
}