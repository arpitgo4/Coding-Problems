 
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

/**
 * Test cases,
 * 
 * baccc 2
 * output: ccbca
 * 
 * zzzazz 2
 * output : zzazz
 */
 
void solve(string& S, int K) {
    map<char,int> oMap;
    for (char c : S) {
        if (oMap.find(c) == oMap.end())
            oMap.insert({ c, 0 });
        
        oMap[c]++;
    }

    string res = "";
    while (!oMap.empty()) {
        auto p = prev(oMap.end());
        char c = p->first;
        int count = p->second;
        oMap.erase(p);

        if (!res.empty() && res.back() == c) {
            if (oMap.empty()) {
                break;
            }

            auto q = prev(oMap.end());
            char q_c = q->first;
            int q_count = q->second;
            oMap.erase(q);

            res += q_c;
            q_count--;

            if (q_count > 0)
                oMap.insert({ q_c, q_count });
        }

        for (int i = 0; i < K && count > 0; i++) {
            res += c;
            count--;
        }

        if (count > 0)
            oMap.insert({ c, count });
    }

    cout << res << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;

    int K;
    cin >> K;

    solve(S, K);
    
    return 0;
}