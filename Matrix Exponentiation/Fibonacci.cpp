// Fibonacci (https://codeforces.com/gym/102644/problem/C)
 
#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
const ll MOD = 1e9 + 7;

vector<vector<ll> multiply_matrix(vector<vector<ll>>& A, vector<vector<ll>>& B) {
    vector<vector<ll>> res;

    return res;
}

vector<vector<ll>> matrix_exponentiation(vector<vector<ll>>& mat, ll p) {
    vector<vector<ll>> res;

    return res;
}

void solve(ll N) {
    vector<vector<ll>> X;
    vector<vector<ll>> Y;

    vector<vector<ll>> mat_exp = matrix_exponentiation(mat, N);
    vector<vector<ll>> res = multiply_matrix(mat_exp, Y);

    cout << res[1][0];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N;
    cin >> N;

    solve(N);
    
    return 0;
}