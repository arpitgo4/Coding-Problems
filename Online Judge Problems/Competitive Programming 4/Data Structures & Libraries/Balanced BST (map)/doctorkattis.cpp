// doctorkattis (https://open.kattis.com/problems/doctorkattis)
 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
 
using namespace std;
 
// Time: O(Q * logN)
// Space: O(N)
 
class Cat {
public:
    string name_;
    int inf_level_, arrival_time_;

    Cat(string& name, int inf_level, int arrival_time) {
        name_ = name;
        inf_level_ = inf_level;
        arrival_time_ = arrival_time;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cmd_cnt;
    cin >> cmd_cnt;
    
    auto cmp = [&](const Cat& c1, const Cat& c2) {
        if (c1.inf_level_ == c2.inf_level_)
            return c1.arrival_time_ < c2.arrival_time_;
        return c1.inf_level_ > c2.inf_level_;
    };
    set<Cat, decltype(cmp)> treatment_queue(cmp);
    unordered_map<string, set<Cat>::iterator> cats;

    int time = 0;
    int query_type, inf_level, inf_incr;
    string cat_name;
    for (int i = 0; i < cmd_cnt; i++) {
        cin >> query_type;
        if (query_type == 0) {
            cin >> cat_name >> inf_level;

            Cat cat(cat_name, inf_level, time++);

            auto p = treatment_queue.insert(cat);
            cats[cat_name] = p.first;
        } else if (query_type == 1) {
            cin >> cat_name >> inf_incr;
            
            auto& cat_itr = cats[cat_name];
            Cat cat = *cat_itr;
            Cat updated_cat(cat.name_, cat.inf_level_ + inf_incr, cat.arrival_time_);

            treatment_queue.erase(cat_itr);
            auto p = treatment_queue.insert(updated_cat);
            cats[cat_name] = p.first;
        } else if (query_type == 2) {
            cin >> cat_name;
            
            auto& cat_itr = cats[cat_name];
            treatment_queue.erase(cat_itr);
        } else if (query_type == 3) {
            if (treatment_queue.empty()) {
                cout << "The clinic is empty" << endl;
            } else {
                auto cat_itr = treatment_queue.begin();
                cout << (*cat_itr).name_ << endl;
            }
        }
    }
    
    return 0;
}