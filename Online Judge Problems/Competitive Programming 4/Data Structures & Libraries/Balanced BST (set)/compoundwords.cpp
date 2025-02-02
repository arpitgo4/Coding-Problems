// compoundwords (https://open.kattis.com/problems/compoundwords)
 
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
 
using namespace std;
 
// Time: O(N^2 * logN)
// Space: O(N^2)
 
void solve(vector<string>& dict) {
    set<string> words;
    int dict_sz = dict.size();
    for (int i = 0; i < dict_sz; i++) {
        for (int j = i+1; j < dict_sz; j++) {
            words.insert(dict[i] + dict[j]);
            words.insert(dict[j] + dict[i]);
        }
    }

    for (string word : words)
        cout << word << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> dict;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);

        string word;
        while (ss >> word) {
            dict.push_back(word);
        }
    }

    solve(dict);

    return 0;
}