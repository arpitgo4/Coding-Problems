// virtualfriends (https://open.kattis.com/problems/virtualfriends)
 
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
 
using namespace std;
 
// Time: O(⍺(N))
// Space: O(N)

using friendship_t = pair<string,string>;

const int MAX_FRIENDS = 1e6;

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

void solve(vector<friendship_t>& friendships, int friendship_cnt) {
    vector<string> words;
    unordered_map<string,int> word_to_idx;

    DisjointSet ds(MAX_FRIENDS);

    for (auto& [ f1, f2 ] : friendships) {
        if (word_to_idx.find(f1) == word_to_idx.end()) {
            words.push_back(f1);
            word_to_idx.insert({ f1, words.size()-1 });
        }

        if (word_to_idx.find(f2) == word_to_idx.end()) {
            words.push_back(f2);
            word_to_idx.insert({ f2, words.size()-1 });
        }

        ds.unionSet(word_to_idx[f1], word_to_idx[f2]);
        cout << ds.getSetSize(word_to_idx[f1]) << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int friendship_cnt;
        cin >> friendship_cnt;
        
        string a, b;
        vector<friendship_t> friendships(friendship_cnt);
        for (int i = 0; i < friendship_cnt; i++) {
            cin >> a >> b;
            friendships[i] = { a, b };
        }

        solve(friendships, friendship_cnt);
    }
    
    return 0;
}