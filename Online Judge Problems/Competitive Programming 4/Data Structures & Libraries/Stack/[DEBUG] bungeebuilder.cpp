// bungeebuilder (https://open.kattis.com/problems/bungeebuilder)
 
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
/**
 * Problem can be, previous/next greater element
 * and previous/next smaller element
 * 
 * Find min and max height of mountain in a given range.
 * Range here, can be denoted as the number of mountains
 * till we have the maximum height mountain in the range
 * Any mountain beyond the max height mountain is not valid
 * for us to be considered in the range, or in problem's words
 * will not be visible/impossible to build a bridge with. 
 * 
 * for next greater element,
 * * monotonically decreasing stack can be used
 * 
 * For minimum, we can build a min stack based on elements
 * and indexes.
 * Minimum query can also be achieved by using a Min Segment
 * Tree but that would increase the time complexity for the 
 * solution to O(NlogN). With stacks only, we can get O(N).
 * 
 * Can't find minimum of a given range with Min Stack.
 * Will use Minimum Segment Tree for above.
 * 
 * Overall,
 * Time: O(NlogN)
 * Space: O(N)
 */

const int INF = INT_MAX;

class MinSegmentTree {
public:
    MinSegmentTree(vector<int>& arr, int arr_sz) {
        tree_.assign(arr_sz * 4, INF);
        buildTree(0, arr_sz-1, 0, arr);
    }

    /**
     * low: lower end of input array
     * high: upper end of input array
     * node_idx: node's index of segment tree
     */
    int buildTree(int low, int high, int node_idx, vector<int>& arr) {
        if (low == high) {
            return tree_[node_idx] = arr[low];
        }

        int mid = (high - low) / 2 + low;
        int left = buildTree(low, mid, 2 * node_idx + 1, arr);
        int right = buildTree(mid+1, high, 2 * node_idx + 2, arr);

        return tree_[node_idx] = min(left, right);
    }

    void printTree() {
        for (int v : tree_) {
            cout << v << " ";
        }
        cout << endl;
    }

    int queryMin(
        int low,
        int high,
        int node_idx,
        int query_low,
        int query_high
    ) {
        if (query_low > query_high) {
            return INF;
        }
        if (low == high) {
            return tree_[node_idx];
        }

        int mid = (high - low) / 2 + low;
        int left = queryMin(low, mid, 2 * node_idx + 1, query_low, min(query_high, mid));
        int right = queryMin(mid+1, high, 2 * node_idx + 2, max(mid+1, query_low), query_high);

        return min(left, right);
    }

private:
    vector<int> tree_;
};

void solve(vector<int>& mountain_height, int mountain_cnt) {
    MinSegmentTree min_seg_tree(mountain_height, mountain_cnt);
    min_seg_tree.printTree();                               // TODO: remove!

    // let's test segment tree implementation first!
    

    // next, test monotonic stack!

    int max_jumping_dist = 0;
    stack<pair<int,int>> mountain_stack;               // { height, index } monotonically decreasing stack
    for (int i = mountain_cnt-1; i >= 0; i--) {
        while (!mountain_stack.empty() && 
                mountain_stack.top().first > mountain_height[i]) {
            
            mountain_stack.pop();
        }

        if (!mountain_stack.empty()) {
            int higher_mountain_idx = mountain_stack.top().second;
            int min_mountain_height = min_seg_tree.queryMin(0, mountain_cnt-1, 0, i+1, higher_mountain_idx-1);
            cout << "min height: " << min_mountain_height << endl;
            if (min_mountain_height != INF) {
                max_jumping_dist = max(
                    max_jumping_dist,
                    mountain_height[i] - min_mountain_height
                );
            }
        }
        
        mountain_stack.push({ mountain_height[i], i });
    }

    // TODO: need reverse iteration too!

    cout << max_jumping_dist << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int mountain_cnt;
    cin >> mountain_cnt;

    vector<int> mountain_height(mountain_cnt);
    for (int i = 0; i < mountain_cnt; i++) {
        cin >> mountain_height[i];
    }

    solve(mountain_height, mountain_cnt);
    
    return 0;
}