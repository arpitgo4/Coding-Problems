// server (https://open.kattis.com/problems/server)
 
#include <iostream>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int task_cnt, total_time;
    cin >> task_cnt >> total_time;

    int time_sum = 0;
    int task_counter = 0;
    int task_time;
    for (int i = 0; i < task_cnt; i++) {
        cin >> task_time;
        if ((task_time + time_sum) > total_time) {
            break;
        }

        time_sum += task_time;
        task_counter++;
    }

    cout << task_counter << endl;
    
    return 0;
}