// countingstars (https://open.kattis.com/problems/countingstars)
 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
 
using namespace std;
 
// Time: O(N * M)
// Space: O(N * M)
 
using grid_t = vector<vector<int>>;

const vector<pair<int,int>> moves{
    { -1, 0 },              // up
    { 1, 0 },               // down
    { 0, -1 },              // left
    { 0, 1 },               // right
};

void exploreStarOnImage(
    int curr_i, 
    int curr_j, 
    grid_t& img, 
    int img_height,
    int img_width,
    grid_t& vis
) {
    vis[curr_i][curr_j] = 1;

    for (auto& [di, dj] : moves) {
        int next_i = curr_i + di,
            next_j = curr_j + dj;

        if (next_i >= 0 && next_i < img_height
            && next_j >= 0 && next_j < img_width
            && img[next_i][next_j] == 1 && vis[next_i][next_j] == 0) {

                exploreStarOnImage(
                    next_i, 
                    next_j,
                    img,
                    img_height,
                    img_width,
                    vis
                );
            }
    }
}

int solve(grid_t& img, int img_height, int img_width) {
    grid_t vis(img_height, vector<int>(img_width, 0));

    int star_cnt = 0;
    for (int i = 0; i < img_height; i++) {
        for (int j = 0; j < img_width; j++) {
            if (vis[i][j] == 0 && img[i][j] == 1) {
                star_cnt++;
                exploreStarOnImage(i, j, img, img_height, img_width, vis);
            }
        }
    }

    return star_cnt;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_id = 0;
    int img_height, img_width;

    string line;
    while (getline(cin, line)) {
        test_id++;

        stringstream ss(line);
        ss >> img_height >> img_width;

        if (img_height <= 0 || img_width <= 0)
            return 0;
   
        grid_t img(img_height, vector<int>(img_width, 0));
        for (int i = 0; i < img_height; i++) {
            for (int j = 0; j < img_width; j++) {
                char c;
                cin >> c;
                if (c == '-') {
                    img[i][j] = 1;
                }
            }
        }

        int star_cnt = solve(img, img_height, img_width);
        cout << "Case " << (test_id) << ": " << star_cnt << endl;

        cin.ignore();
    }
    
    return 0;
}