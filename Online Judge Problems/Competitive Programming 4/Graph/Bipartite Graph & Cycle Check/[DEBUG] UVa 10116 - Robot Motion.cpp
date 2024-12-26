// UVa 10116 - Robot Motion (https://onlinejudge.org/external/101/10116.pdf)
 
#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
// Time: O(N * M)
// Space: O(1)

#define f first
#define s second
#define START { 0, E-1 }
 
typedef pair<int,int> pos;

int N, M, E;
vector<vector<char>> G;

pos EXIT_POS{ -1, -1 };

unordered_map<char, pair<int,int>> moves{
    { 'N', { -1, 0 } },                  // up                  
    { 'S', { 1, 0 } },                   // down
    { 'W', { 0, -1 } },                  // left
    { 'E', { 0, 1 } }                    // right
};

bool is_exit(pos& curr) {
    return curr.f < 0 || curr.f == N || curr.s < 0 || curr.s == M;
}

pair<int,int> next(pos curr) {
    if (curr == EXIT_POS)
        return EXIT_POS;

    char move_char = G[curr.f][curr.s];
    auto& move = moves[move_char];
    pos next_curr = { curr.f + move.f, curr.s + move.s };
    if (is_exit(next_curr))
        return EXIT_POS;

    return next_curr;
}

void solve(int N, int M, int E) {
    int exit_cnt = 0;
    pos hare = START, tort = START;
    do {
        if (is_exit(hare)) {
            // find exit length
            tort = START;
            while (tort != EXIT_POS) {
                tort = next(tort);
                exit_cnt++;
            }

            cout << exit_cnt << " step(s) to exit" << endl; 
            return;
        }

        tort = next(tort);
        hare = next(next(hare));
    } while(tort != hare);

    // cycle found

    // find cycle start
    int cycle_cnt = 0, pre_cycle_cnt = 0;
    tort = START;
    while (tort != hare) {
        tort = next(tort);
        hare = next(hare);
        pre_cycle_cnt++;
    }

    // find cycle length
    hare = tort;
    do {
        hare = next(hare);
        cycle_cnt++;
    } while (hare != tort);

    cout << pre_cycle_cnt << " step(s) before a loop of " << cycle_cnt << " step(s)" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> E;
    
    while (N > 0 && M > 0 && E > 0) {
        G.assign(N, vector<char>(M));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> G[i][j];
            }
        }
        
        solve(N, M, E);

        cin >> N >> M >> E;
    }
    
    return 0;
}