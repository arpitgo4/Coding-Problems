// Radio Station (https://codeforces.com/problemset/problem/918/B)
 
#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    unordered_map<string,string> uMap;

    string name, ip;
    for (int i = 0; i < N; i++) {
        cin >> name >> ip;
        uMap[ip] = name;
    }

    for (int i = 0; i < M; i++) {
        cin >> name >> ip;
        string q = ip.substr(0, ip.length()-1);
        cout << name << " " << ip << " #" << uMap[q] << endl;
    }
    
    return 0;
}