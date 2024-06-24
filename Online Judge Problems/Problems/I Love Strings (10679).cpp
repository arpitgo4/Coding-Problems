// I Love Strings!!! (10679) (https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2637)
 
#include <iostream>
#include <vector>

using namespace std;
 
/**
 * Giving WA in Uva
 */

// Time: O(N + M)
// Space: O(M)

const int MAX_N = 1e6 + 100;
const int ALPHABET = 256;

vector<vector<int>> T;                                  // suffix-link tree
vector<bool> visited, match;

int node_counter;

class TrieNode {
public:
    int node_id;
    vector<int> pat_indices;
    vector<TrieNode*> next;
    vector<TrieNode*> go;
    bool is_word;
    TrieNode* parent;
    TrieNode* link;
    char par_ch;
    TrieNode() {
        this->node_id = ++node_counter;
        this->next.assign(ALPHABET, NULL);
        this->go.assign(ALPHABET, NULL);
        this->is_word = false;
        this->parent = NULL;
        this->link = NULL;
        this->par_ch = '$';
        this->pat_indices = vector<int>();
    }

    TrieNode(TrieNode* parent, char par_ch) : TrieNode() {
        this->parent = parent;
        this->par_ch = par_ch;
    }
};

TrieNode* root;
vector<TrieNode*> nodes;

void insert_trie(string& S, int pat_idx) {
    TrieNode* node = root;
    for (char c : S) {
        int i = c;
        if (node->next[i] == NULL) 
            node->next[i] = new TrieNode(node, c);
        node = node->next[i];
        nodes[node->node_id] = node;
    }

    node->is_word = true;
    node->pat_indices.push_back(pat_idx);
}

TrieNode* go(TrieNode* node, char c);

TrieNode* get_link(TrieNode* node) {
    if (node->link == NULL) {
        if (node == root || node->parent == root)
            node->link = root;
        else {
            TrieNode* par_link = get_link(node->parent);
            node->link = go(par_link, node->par_ch);
        }
    }

    return node->link;
}

TrieNode* go(TrieNode* node, char c) {
    int i = c;
    if (node->go[i] == NULL) {
        if (node->next[i] != NULL)
            node->go[i] = node->next[i];
        else {
            TrieNode* link = get_link(node);
            node->go[i] = (node == root) ? root : go(link, c);
        }
    }

    return node->go[i];
}

bool dfs(int u, int p) {
    bool found = visited[u];
    for (int v : T[u])
        if (v != p)
            found = dfs(v, u) || found;

    if (found && nodes[u]->is_word) {
        for (int pat_idx : nodes[u]->pat_indices)
            match[pat_idx] = true;
    }

    return found;    
}

void solve(string& S, vector<string>& patterns, int K) {
    T.assign(MAX_N, vector<int>());
    visited.assign(MAX_N, false);
    nodes.assign(MAX_N, NULL);
    match.assign(K, false);
    node_counter = 0;

    root = new TrieNode();

    for (int i = 0; i < K; i++)
        insert_trie(patterns[i], i);

    // builds suffix link tree
    nodes[root->node_id] = root;
    for (int i = 1; i <= node_counter; i++) {
        TrieNode* node = nodes[i];
        TrieNode* link = get_link(node);

        T[node->node_id].push_back(link->node_id);
        T[link->node_id].push_back(node->node_id);
    }

    TrieNode* node = root;
    for (char c : S) {
        node = go(node, c);
        visited[node->node_id] = true;
    }

    dfs(root->node_id, -1);

    for (bool found : match)
        cout << (found ? "y" : "n") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        int K;
        cin >> K;

        vector<string> patterns(K);
        for (int i = 0; i < K; i++)
            cin >> patterns[i];

        solve(S, patterns, K);
    }
    
    return 0;
}