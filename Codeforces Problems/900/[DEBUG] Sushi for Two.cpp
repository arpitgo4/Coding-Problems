// Sushi for Two (https://codeforces.com/problemset/problem/1138/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
/**
 * Use Two Pointers technique to find the segment!
 * 
 * Fix one of the pointer (i) and try different segments with
 * other pointer (j).
 * 
 * Naive Algorithm,
 * Time: O(N^2)
 * Space: O(1)
 * 
 * In case I use Segment tree, merge function for each segment
 * will have O(1) time complexity as each segment node will contain
 * count for both types of Sushis and number of Sushis is fixed (2)
 * In this case, query function for segment tree will be complex and 
 * difficult to implement
 * 
 * Time: O(N + logN)
 * 
 * In case if I use prefix sum technique and pair that up with (binary??) 
 * search we can speed up finding optimal location for j pointer
 * In this case, complexity of operations is being divided into 2 parts
 * (prefix sums & binary search). Easier to implement.
 * 
 * Time: O(N + logN)
 * 
 * For a segment to be valid,
 * 1. Segment should have both sushis
 * 2. Sushis should be divided into both halves of the segment
 * 
 * From ith pointer, find the max position for jth pointer such that
 * A[j..i] = either { 1 or 2 }
 * then, check if the window is valid by checking other half of above
 * window if that contains only other Sushi
 * 
 * 
 */

vector<vector<int>> PF;

void prefix_array(vector<int>& A, int N) {
    PF.assign(N, vector<int>(3, 0));

    PF[0][A[0]] = 1;
    for (int i = 1; i < N; i++) {
        PF[i] = PF[i-1];
        PF[i][A[i]]++;
    }
}

pair<int,int> query(int l, int h) {
    if (l == 0)
        return { PF[h][1], PF[h][2] };

    return {
        PF[h][1] - PF[l-1][1],
        PF[h][2] - PF[l-1][2]
    };
}

void solve(vector<int>& A, int N) {
    prefix_array(A, N);

    int max_len = 0;
    for (int i = 1; i < N; i++) {
        int l = 0, h = i;
        while (l <= h) {
            int m = (h-l)/2 + l;
            auto p = query(m, i);
            int len = i-m+1;
            auto q = query(max(0, m-len), max(0, m-1));
            if ((p.first == 0 && q.second == 0) || (p.second == 0 && q.first == 0)) {
                max_len = max(max_len, 2*len);
                h = m-1;
            } else {
                l = m+1;
            }
        }
    }

    cout << max_len << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);
    
    return 0;
}