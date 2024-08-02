// Sum of Different Primes (1213) (https://onlinejudge.org/external/12/1213.pdf)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N^2 * K)
// Space: O(N^2 * K)
 
const int MAX_N = 1120 + 1;
const int MAX_K = 14 + 1;

vector<int> primes;
vector<vector<vector<int>>> dp(MAX_N, vector<vector<int>>(MAX_N, vector<int>(MAX_K, -1)));

void sieve_of_eratosthenes() {
    vector<bool> prime(MAX_N+1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i])
            continue;
        for (int x = i+i; x <= MAX_N; x += i)
            prime[x] = false;
    }

    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i])
            primes.push_back(i);
    }
}

int dfs(int i, int n, int k) {
    if (n == 0 && k == 0)
        return 1;
    if (n <= 0 || k <= 0 || primes[i] > n || i == primes.size())
        return 0;
    if (dp[i][n][k] != -1)
        return dp[i][n][k];

    int count = 0;
    count += dfs(i+1, n-primes[i], k-1);
    count += dfs(i+1, n, k);

    return dp[i][n][k] = count;
}

void solve(int N, int K) {
    int count = dfs(0, N, K);
    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    sieve_of_eratosthenes();

    while (N != 0 && K != 0) {
        solve(N, K);

        cin >> N >> K;
    }
    
    return 0;
}