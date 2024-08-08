// Slogan Learning of Princess (12592)
 
#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

unordered_map<string,string> dict;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    string line;
    getline(cin, line);

    vector<string> lines(2*N);
    for (int i = 0; i < 2*N; i++) {
        getline(cin, line);
        lines[i] = line;
    }

    for (int i = 0; i < 2*N; i+=2)
        dict.insert({ lines[i], lines[i+1] });

    int Q;
    cin >> Q;

    getline(cin, line);
    for (int i = 0; i < Q; i++) {
        getline(cin, line);
        cout << dict[line] << endl;
    }
    
    return 0;
}