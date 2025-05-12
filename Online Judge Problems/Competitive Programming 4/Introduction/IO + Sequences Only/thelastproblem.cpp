// thelastproblem (https://open.kattis.com/problems/thelastproblem)
 
#include <iostream>
#include <string>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string line;
    getline(cin, line);
    
    cout << "Thank you, " << line << ", and farewell!" << endl;
    
    return 0;
}