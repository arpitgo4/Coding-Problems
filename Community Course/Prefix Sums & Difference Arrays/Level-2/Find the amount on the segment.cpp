// Find the amount on the segment (https://codeforces.com/edu/course/3/lesson/10/2/practice/contest/324367/problem/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
// Time: O(N)
// Space: O(N)

vector<ll> PREFIX_ARRAY;

ll query(int l, int r) {
    return PREFIX_ARRAY[r] - PREFIX_ARRAY[l-1];
}

void build_prefix_array(vector<ll>& A, int N) {
    PREFIX_ARRAY.assign(N+1, 0);        // adding padding in front of the array for easier build and query
    for (int i = 1; i < N+1; i++)
        PREFIX_ARRAY[i] = PREFIX_ARRAY[i-1] + A[i-1];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    build_prefix_array(A, N);

    int Q;
    cin >> Q;

    vector<ll> res;
    int l, r;
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        res.push_back(query(l, r));
    }

    for (ll r : res)
        cout << r << endl;
    
    return 0;
}