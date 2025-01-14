// lost (https://open.kattis.com/problems/lost)
 
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <climits>
#include <queue>
#include <tuple>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)
 
constexpr int INF = INT_MAX;
constexpr int MAX_LANG_CNT = 1e4;
constexpr int ENG_IDX = 0;

using translation_t = tuple<int,int,int>;
using graph_edge_t = pair<int,int>;
using graph_t = vector<vector<graph_edge_t>>;

/**
 * Do BFS from `English`,
 * maintain distance and cost for each language
 * 
 * 1. If target lang is discoverd, check if curr_distance < stored_distance
 *    1. If yes, store new cost
 * 2. If curr_distance == stored_distance
 *    1. Take minimum of the costs
 * 
 * Print the summation of the costs for all target_langs
 */

void findMinDistanceAndCost(graph_t& adj_list, vector<int>& cost, vector<int>& dist, vector<int>& vis, vector<int>& parent) {
    queue<int> lang_queue;
    lang_queue.push(ENG_IDX);
    vis[ENG_IDX] = 1;
    dist[ENG_IDX] = 0;
    cost[ENG_IDX] = 0;

    while (!lang_queue.empty()) {
        int curr = lang_queue.front();
        lang_queue.pop();

        if (vis[curr] == 2)
            continue;

        for (auto& [ next, c ] : adj_list[curr]) {
            if (vis[next] == 0) {
                lang_queue.push(next);
                vis[next] = 1;
                dist[next] = dist[curr] + 1;
                cost[next] = c;
                parent[next] = curr;
            } else {                                                    // back-edge or cross-edge
                if (dist[next] == dist[curr] + 1) {
                    if (cost[next] > c) {
                        cost[next] =  c;
                        parent[next] = curr;    
                    }
                }
            }
        }

        vis[curr] = 2;
    }
}

void buildGraph(string& target_langs, int target_lang_cnt, vector<string>& translators, int translator_cnt, graph_t& adj_list, vector<string>& words, unordered_map<string,int>& word_to_idx) {
    string word;

    words.push_back("English");
    word_to_idx.insert({ words.back(), ENG_IDX });

    stringstream ss(target_langs);
    while (ss >> word) {
        words.push_back(word);
        word_to_idx.insert({ word, words.size()-1 });
    }

    for (string& line : translators) {
        stringstream ss(line);

        int c;
        string l1, l2;
        ss >> l1 >> l2 >> c;

        if (word_to_idx.find(l1) == word_to_idx.end()) {
            words.push_back(l1);
            word_to_idx.insert({ l1, words.size()-1 });
        }
        if (word_to_idx.find(l2) == word_to_idx.end()) {
            words.push_back(l2);
            word_to_idx.insert({ l2, words.size()-1 });
        }
        
        adj_list[word_to_idx[l1]].push_back({ word_to_idx[l2], c });
        adj_list[word_to_idx[l2]].push_back({ word_to_idx[l1], c });
    }
}

void solve(string& target_langs, int target_lang_cnt, vector<string>& translators, int translator_cnt) {
    vector<string> words;
    unordered_map<string,int> word_to_idx;
    graph_t adj_list(MAX_LANG_CNT, vector<graph_edge_t>());
    
    buildGraph(target_langs, target_lang_cnt, translators, translator_cnt, adj_list, words, word_to_idx);

    vector<int> parent(MAX_LANG_CNT, -1);
    vector<int> vis(MAX_LANG_CNT, 0);
    vector<int> cost(MAX_LANG_CNT, INF);
    vector<int> dist(MAX_LANG_CNT, -1);

    iota(parent.begin(), parent.end(), 0);

    findMinDistanceAndCost(adj_list, cost, dist, vis, parent);

    unordered_set<int> target_langs_set;
    string lang;
    stringstream ss1(target_langs);
    while (ss1 >> lang) {
        target_langs_set.insert(word_to_idx[lang]);
    }

    int total_cost = 0;
    stringstream ss(target_langs);
    while (ss >> lang) {
        int curr = word_to_idx[lang];

        if (cost[curr] == INF) {
            cout << "Impossible" << endl;
            return;
        }

        while (parent[curr] != curr) {
            total_cost += cost[curr];

            if (target_langs_set.find(parent[curr]) != target_langs_set.end())
                break;

            curr = parent[curr];
        }
    }

    cout << total_cost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int target_lang_cnt, translator_cnt;
    cin >> target_lang_cnt >> translator_cnt;

    cin.ignore();

    string target_langs;
    getline(cin, target_langs);
    
    string line;
    vector<string> translators(translator_cnt);
    for (int i = 0; i < translator_cnt; i++) {
        getline(cin, line);
        translators[i] = line;
    }

    solve(target_langs, target_lang_cnt, translators, translator_cnt);
    
    return 0;
}