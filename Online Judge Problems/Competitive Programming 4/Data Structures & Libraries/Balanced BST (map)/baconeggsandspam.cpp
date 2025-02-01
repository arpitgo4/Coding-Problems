// baconeggsandspam (https://open.kattis.com/problems/baconeggsandspam)
 
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int order_cnt;
    cin >> order_cnt;
    
    while (order_cnt != 0) {
        cin.ignore();

        map<string, vector<string>> name_to_order;

        string line;
        for (int i = 0; i < order_cnt; i++) {
            getline(cin, line);

            stringstream ss(line);
            string name, order;
            ss >> name;
            while (ss >> order) {
                if (name_to_order.find(order) == name_to_order.end()) {
                    name_to_order.insert({ order, *new vector<string>() });
                }

                name_to_order[order].push_back(name);
            }
        }

        for (auto& [ name, list ] : name_to_order) {
            sort(list.begin(), list.end());
            cout << name;
            for (string order : list) {
                cout << " " << order;
            }
            cout << endl;
        }
        cout << endl;

        cin >> order_cnt;
    }
    
    return 0;
}