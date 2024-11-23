// Kefa and Company (https://codeforces.com/problemset/problem/580/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
/**
 * Filter out all the friends that are within D difference
 * in money from each other.
 * 
 * Above subset is eligible to be called for the party!
 * 
 * If no subset can be found, then pick the friend with
 * maximum friendship factor!
 * 
 * If filtered subset has less friendship factor than the
 * single friend that is not part of subset but has more
 * friendship factor with Kefa, then single friend will be 
 * the invitee.
 * 
 * Can we use DSU here to create subsets and pick the final 
 * subset with max friendship factor?
 * 
 * Friend with minimum money can represent the money value for
 * whole subset and this value can be used to check if any new
 * friend can be part of the subset.
 * 
 * A group (subset) can be represented as a **line** (as interval)
 * with min and max bounds. All members within the group will 
 * exist within/on the bounds.
 * 
 * We can sort all the friends by money first. With sorting all the 
 * friends with money in close range will come adjacent to each other.
 * Just like merging intervals data.
 * While looking for a group (subset) for them will become easier
 * as we have to look before or ahead of them??
 * 
 * So, this problem can be paraphrased as,
 * 1. Merge interval together
 * 2. Find from final merged intervals, an interval with
 *    highest certain metric (friendship score)
 * 
 */

typedef long long ll;

vector<int> ordP;
vector<ll> prfx_f;

void print_vector(vector<int>& A) {
    for (int a : A)
        cout << a << " ";
    cout << endl;
}
void print_vector(vector<ll>& A) {
    for (int a : A)
        cout << a << " ";
    cout << endl;
}

void build_prfx_sum(vector<int>& F, int N) {
    prfx_f.assign(N, 0);
    prfx_f[0] = F[ordP[0]];
    for (int i = 1; i < N; i++) {
        int idx = ordP[i];
        prfx_f[i] = prfx_f[i-1] + F[idx];
    }
}

ll query_prfx_sum(int l, int h) {
    if (l == 0)
        return prfx_f[h];
    return prfx_f[h] - prfx_f[l-1];
}

void solve(vector<int>& M, vector<int>& F, int N, int D) {
    ordP.assign(N, 0);
    iota(ordP.begin(), ordP.end(), 0);

    auto cmp = [&](const int i, const int j) {
        return M[i] < M[j];
    };
    sort(ordP.begin(), ordP.end(), cmp);

    build_prfx_sum(F, N);

    print_vector(ordP);
    print_vector(prfx_f);

    ll max_frnd = 0;
    for (int i : ordP) {
        /**
         * TODO: debug, some fun business with iterator being returned from
         *       `upper_bound` call.
         */
        cout << "idx: " << i << ", M: " << M[i] << endl;
        auto itr = upper_bound(ordP.begin(), ordP.end(), M[i]-D, cmp);
        cout << "iterator: " << *itr << endl;
        int l = upper_bound(ordP.begin(), ordP.end(), M[i]-D, cmp) - ordP.begin();
        int h = upper_bound(ordP.begin(), ordP.end(), M[i]+D-1, cmp) - ordP.begin();

        // TODO: need to add if-else before finalising `l` & `h` values

        cout << "l: " << l << ", h: " << h << ", sum: " << query_prfx_sum(l, h) << endl;

        max_frnd = max<ll>(max_frnd, query_prfx_sum(l, h));
    }
    
    cout << max_frnd << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, D;
    cin >> N >> D;
    
    vector<int> M(N), F(N);
    for (int i = 0; i < N; i++)
        cin >> M[i] >> F[i];

    solve(M, F, N, D);
    
    return 0;
}