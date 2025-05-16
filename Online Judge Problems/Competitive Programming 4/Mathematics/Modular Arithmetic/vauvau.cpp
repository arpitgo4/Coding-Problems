// vauvau (https://open.kattis.com/problems/vauvau)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
class DogMood {
public:
    int aggresive_duration_;
    int calm_duration_;

    DogMood(int agg_duration, int calm_duration) {
        this->aggresive_duration_ = agg_duration;
        this->calm_duration_ = calm_duration;
    }
};

void printDogAttackCount(
    DogMood& d1,
    DogMood& d2,
    int man_arrv_time
) {
    int dog_attack_cnt = 0;
    int d1_mood = man_arrv_time % (d1.aggresive_duration_ + d1.calm_duration_);
    if (d1_mood > 0 && d1_mood <= d1.aggresive_duration_) {
        dog_attack_cnt++;
    }

    int d2_mood = man_arrv_time % (d2.aggresive_duration_ + d2.calm_duration_);
    if (d2_mood > 0 && d2_mood <= d2.aggresive_duration_) {
        dog_attack_cnt++;
    }

    if (dog_attack_cnt == 0) {
        cout << "none" << endl;
    } else if (dog_attack_cnt == 1) {
        cout << "one" << endl;
    } else {
        cout << "both" << endl;
    }    
}

void solve(
    DogMood& d1,
    DogMood& d2,
    int postman_arrv_time,
    int milkman_arrv_time,
    int garbageman_arrv_time) {
    
    printDogAttackCount(d1, d2, postman_arrv_time);
    printDogAttackCount(d1, d2, milkman_arrv_time);
    printDogAttackCount(d1, d2, garbageman_arrv_time);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int d1_agg_time, d1_calm_time,
        d2_agg_time, d2_calm_time;
    cin >> d1_agg_time >> d1_calm_time >> d2_agg_time >> d2_calm_time;

    DogMood d1(d1_agg_time, d1_calm_time);
    DogMood d2(d2_agg_time, d2_calm_time);
    
    int postman_arrv_time, milkman_arrv_time, garbageman_arrv_time;
    cin >> postman_arrv_time >> milkman_arrv_time >> garbageman_arrv_time;

    solve(
        d1,
        d2,
        postman_arrv_time,
        milkman_arrv_time,
        garbageman_arrv_time
    );
    
    return 0;
}