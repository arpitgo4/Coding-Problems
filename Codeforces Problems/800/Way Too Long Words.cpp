// Way Too Long Words (https://codeforces.com/problemset/problem/71/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
  
void solve(vector<string>& words, int N) {
    for (string& word : words) {
        if (word.length() > 10)
            word = word[0] + to_string(word.length()-2) + word[word.length()-1];

        cout << word << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; i++)
        cin >> words[i];

    solve(words, N);
    
    return 0;
}