// warehouse (https://open.kattis.com/problems/warehouse)
 
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
 
using namespace std;
 
// Time: O()
// Space: O()
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int shipment_cnt;
        cin >> shipment_cnt;
        
        unordered_map<string,int> shipment_to_cnt;

        string toy_name; 
        int toy_cnt;
        for (int i = 0; i < shipment_cnt; i++) {
            cin >> toy_name >> toy_cnt;
            shipment_to_cnt[toy_name] += toy_cnt;
        }

        auto cmp = [&](const int a, const int b) {
            return a > b;
        };
        map<int,vector<string>,decltype(cmp)> cnt_to_shipment(cmp);
        for (auto& [ toy_name, toy_cnt ] : shipment_to_cnt) {
            if (cnt_to_shipment.find(toy_cnt) == cnt_to_shipment.end()) {
                cnt_to_shipment.insert({ toy_cnt, *new vector<string>()});
            }

            cnt_to_shipment[toy_cnt].push_back(toy_name);
        }

        cout << shipment_to_cnt.size() << endl;
        for (auto& [ toy_cnt, toy_names ] : cnt_to_shipment) {
            sort(toy_names.begin(), toy_names.end());
            for (string& toy_name : toy_names)
                cout << toy_name << " " << toy_cnt << endl;
        }
    }
    
    return 0;
}