// Oil business (https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/H)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O()
// Space: O()

// Total edges weight = W
// Deleted edges weight <= S
// Spanning tree with weight, weight(ST) = M
// Weight of deleted edges = W-M
// in-equality to satisfy, (W-M) <= S
// W, S are constants, M is the only variable

// build spanning tree such that, final weight of the tree satisfy above in-equality

// in minimum spanning tree, we build final tree greedily using smallest weights possible
// brute-force recursion can be used to try multiple alternative weighted edges to form
// final tree which satisfies above in-equality

void solve() {
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}