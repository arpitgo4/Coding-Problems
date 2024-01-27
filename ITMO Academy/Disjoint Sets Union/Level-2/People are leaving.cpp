// People are leaving (https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/A)
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithms>
 
using namespace std;
 
// Time: O(⍺(N))
// Space: O(N)

// Cache the response by saving the nearest person for the index i,
// thereby making the further queries O(1), path compression heuristics
// similar kind of heuristics to speed-up disjoint sets

vector<int> P, S;

void init(int N) {
    P.assign(N+1, -1);
    S.assign(N+1, 0);
    for (int i = 1; i < N+1; i++) {
        P[i] = i;
        S[i] = 1;
    }
}

// find root of the set
int next_person(int x, int N) {
    if (x > N || x == -1)
        return -1;
    if (P[x] != x)
        P[x] = next_person(P[x], N);

    return P[x];
}

// union two sets
void remove_person(int x, int N) {
    P[x] = next_person(x+1, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    init(N);

    // we can also read strings by giving `string format`
    // scanf("%s%d", s, &x);
    string line;
    for (int i = 0; i < Q+1; i++) {
        getline(cin, line);

        // first read is empty string...
        if (line.length() == 0)
            continue;

        char type = line[0];
        string sub_str = line.substr(2, line.length()-2);
        int x = stoi(sub_str);
        if (type == '-')
            remove_person(x, N);
        else
            cout << next_person(x, N) << endl;
    }
    
    return 0;
}