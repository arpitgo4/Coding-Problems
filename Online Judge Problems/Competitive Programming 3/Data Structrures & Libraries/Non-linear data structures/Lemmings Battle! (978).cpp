// Lemmings Battle! (978)
 
#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)

void solve(int N, vector<int>& pow_g, int G, vector<int>& pow_b, int B) {
    priority_queue<int> pq_g(pow_g.begin(), pow_g.end());               // max-heaps
    priority_queue<int> pq_b(pow_b.begin(), pow_b.end());

    while (pq_g.size() > 0 && pq_b.size() > 0) {

        vector<pair<int,int>> fight;
        for (int i = 0; i < N && pq_g.size() > 0 && pq_b.size() > 0; i++) {
            int g = pq_g.top();
            pq_g.pop();

            int b = pq_b.top();
            pq_b.pop();

            if (g > b)
                fight.push_back({ g-b, 0 });
            else if (b > g)
                fight.push_back({ b-g, 1 });
        }

        for (auto& p : fight)
            if (p.second == 0)
                pq_g.push(p.first);
            else pq_b.push(p.first);
    }

    if (pq_g.size() > 0) {
        cout << "green wins" << endl;
        while (pq_g.size() > 0) {
            cout << pq_g.top() << endl;
            pq_g.pop();
        }
    } else if (pq_b.size() > 0) {
        cout << "blue wins" << endl;
        while (pq_b.size() > 0) {
            cout << pq_b.top() << endl;
            pq_b.pop();
        }
    } else {
        cout << "green and blue died" << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, G, B;
        cin >> N >> G >> B;

        vector<int> pow_g(G), pow_b(B);
        for (int i = 0; i < G; i++)
            cin >> pow_g[i];

        for (int i = 0; i < B; i++)
            cin >> pow_b[i];

        solve(N, pow_g, G, pow_b, B);
        if (T != 0)
            cout << endl;
    }
    
    return 0;
}