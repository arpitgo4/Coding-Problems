// squarepegs (https://open.kattis.com/problems/squarepegs)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
double calculateHypotenuse(double base, double height) {
    return sqrt((base * base) + (height * height));
}

void solve(
    vector<double>& circ_plot_radius,
    int circ_plot_cnt,
    vector<double>& circ_house_radius,
    int circ_house_cnt,
    vector<double>& sq_house_side,
    int sq_house_cnt
) {

    multiset<double> plot_set(circ_plot_radius.begin(), circ_plot_radius.end());

    int placed_house_cnt = 0;
    for (int i = 0; i < circ_house_cnt; i++) {
        auto itr = plot_set.lower_bound(circ_house_radius[i] + 1);
        if (itr != plot_set.end()) {
            plot_set.erase(itr);
            placed_house_cnt++;
        }
    }

    for (int i = 0; i < sq_house_cnt; i++) {
        int side = sq_house_side[i];
        double hypot_len = calculateHypotenuse(side, side);
        auto itr = plot_set.lower_bound((hypot_len / 2.0) + 1);
        if (itr != plot_set.end()) {
            plot_set.erase(itr);
            placed_house_cnt++;
        }
    }

    cout << placed_house_cnt << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int circ_plot_cnt, circ_house_cnt, sq_house_cnt;
    cin >> circ_plot_cnt >> circ_house_cnt >> sq_house_cnt;
    
    vector<double> circ_plot_radius(circ_plot_cnt);
    for (int i = 0; i < circ_plot_cnt; i++) {
        cin >> circ_plot_radius[i];
    }

    vector<double> circ_house_radius(circ_house_cnt);
    for (int i = 0; i < circ_house_cnt; i++) {
        cin >> circ_house_radius[i];
    }

    vector<double> sq_house_side(sq_house_cnt);
    for (int i = 0; i < sq_house_cnt; i++) {
        cin >> sq_house_side[i];
    }

    solve(
        circ_plot_radius,
        circ_plot_cnt,
        circ_house_radius,
        circ_house_cnt,
        sq_house_side,
        sq_house_cnt
    );
    
    return 0;
}