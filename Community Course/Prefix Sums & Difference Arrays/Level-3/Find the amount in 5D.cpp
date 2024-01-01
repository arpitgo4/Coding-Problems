// Find the amount in 5D (https://codeforces.com/edu/course/3/lesson/10/3/practice/contest/324368/problem/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
// Time: O(N^5)
// Space: O(N^5)

vector<vector<ll>> prefix_sum_2D;
vector<vector<ll>> prefix_sum_4D;
vector<ll> prefix_sum_5D;

ll query(int i1, int j1, int i2, int j2, int i3, int j3, int i4, int j4, int i5, int j5) {
    return -1ll;
}

void build_5D_prefix_sum_array(vector<vector<vector<vector<vector<ll>>>>>& A, int N1, int N2, int N3, int N4, int N5) {
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N1, N2, N3, N4, N5;
    cin >> N1 >> N2 >> N3 >> N4 >> N5;

    vector<vector<vector<vector<vector<ll>>>>> A(N1, vector<ll>(N2, vector<ll>(N3, vector<ll>(N4, vector<ll>(N5, 0)))));
    for (int i = 0; i < N1; i++)
        for (int j = 0; j < N2; j++)
            for (int k = 0; k < N3; k++)
                for (int p = 0; p < N4; p++)
                    for (int q = 0; q < N5; q++)
                        cin >> A[i][j][k][p][q];

    int Q;
    cin >> Q;

    int i1, j1, i2, j2, i3, j3, i4, j4, i5, j5;
    for (int i = 0; i < Q; i++) {
        cin >> i1 >> j1 >> i2 >> j2 >> i3 >> j3 >> i4 >> j4 >> i5 >> j5;
        cout << query(i1, j1, i2, j2, i3, j3, i4, j4, i5, j5) << endl;
    }
    
    return 0;
}