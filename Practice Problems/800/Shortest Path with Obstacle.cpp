// Shortest Path with Obstacle (https://codeforces.com/contest/1547/problem/A)
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
// if A & B are in straight line, then there is only one shortest path from A -> B
// and if F is on that path, just +2 to manhattan(A, B)
// otherwise, there is always a way to avoid obstacle and take the shortest path, i.e. 
// manhattan(A, B)

// need min & max functions, because A and B can be either before or after each other
// both vertically and horizontally

void solve(pair<int,int>& A, pair<int,int>& B, pair<int,int>& F) {
    int dist_a_b = abs(A.first - B.first) + abs(A.second - B.second);

    // A, B & F in-line vertically & F lies in-between them
    if (A.first == B.first 
            && A.first == F.first 
            && min(A.second,B.second) < F.second && F.second < max(A.second,B.second))
        cout << (dist_a_b + 2) << endl;
    
    // A, B & F in-line horizontally & F lies in-between them
    else if (A.second == B.second 
            && A.second == F.second 
            && min(A.first,B.first) < F.first && F.first < max(A.first,B.first))
        cout << (dist_a_b + 2) << endl;
        
    else cout << dist_a_b << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    int x, y;
    while (T--) {
        cin >> x >> y;
        pair<int,int> A = { x , y };

        cin >> x >> y;
        pair<int,int> B = { x , y };

        cin >> x >> y;
        pair<int,int> F = { x , y };

        solve(A, B, F);
    }   
    
    return 0;
}