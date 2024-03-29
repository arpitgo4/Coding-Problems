// ADAINDEX - Ada and Indexing (https://www.spoj.com/problems/ADAINDEX/)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// N: number of strings
// M: max length of a string
// Time: O(N * M + M)
// Space: O(N * M)
 
const int ALPHA_SIZE = 26;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool is_word;
    int count;
    TrieNode() {
        this->children.assign(ALPHA_SIZE, NULL);
        this->is_word = false;
        this->count = 1;
    }
}root;

void insert_trie(string& word) {
    TrieNode* node = &root;
    for (char c : word) {
        int idx = c - 'a';
        if (node->children[idx] == NULL)
            node->children[idx] = new TrieNode();
        else node->children[idx]->count++;

        node = node->children[idx];
    }

    node->is_word = true;
}

int dfs(string& prefix) {
    TrieNode* node = &root;
    for (char c : prefix) {
        int idx = c - 'a';
        if (node->children[idx] == NULL)
            return 0;

        node = node->children[idx];
    }

    return node->count;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    string word;
    for (int i = 0; i < N; i++) {  
        cin >> word;
        insert_trie(word);
    }

    string prefix;
    for (int i = 0; i < Q; i++) {
        cin >> prefix;
        cout << dfs(prefix) << endl;
    }
    
    return 0;
}