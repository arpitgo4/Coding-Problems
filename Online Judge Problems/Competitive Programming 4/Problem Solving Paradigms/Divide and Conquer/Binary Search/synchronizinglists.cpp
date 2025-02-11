// synchronizinglists (https://open.kattis.com/problems/synchronizinglists)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
void solve(vector<int>& list_1, vector<int>& list_2, int list_sz) {
    map<int,int> list_1_map;

    for (int x : list_1)
        list_1_map[x] = -1;

    sort(list_2.begin(), list_2.end());

    int i = 0;
    for (auto& [x, _] : list_1_map) {
        list_1_map[x] = list_2[i];
        i++;
    }

    for (int x : list_1) {
        cout << list_1_map[x] << endl;
    }
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int list_sz;
    cin >> list_sz;

    while (list_sz > 0) {
        vector<int> list_1(list_sz);
        for (int i = 0; i < list_sz; i++)
            cin >> list_1[i];

        vector<int> list_2(list_sz);
        for (int i = 0; i < list_sz; i++)
            cin >> list_2[i];

        solve(list_1, list_2, list_sz);

        cin >> list_sz;
    }
    
    return 0;
}