#include <iostream>
#include <vector>

using namespace std;

/*
You are given an m * n integer matrix with the following two properties:

1. Each row is sorted in non-decreasing order.
2. The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return `true` if target is in matrix or `false` otherwise.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 33
Output: false

Constraints:
  m == matrix.length
  n == matrix[i].length
  1 <= m, n <= 100
  -10^4 <= matrix[i][j], target <= 10^4

*/

// Efficient Solution
// Binary Searches
// Time: O(MlogN)
// Space: O(1)

// Better Solution
// Time: O(N + M) 
// Space: O(1)

// O(M + logN) < O(N + M)

// [0,0] => 1
// 

// index_of(i,j) => (sz_row * row_idx + col_idx)

// lower_bound = 0, upper_bound = N*M-1
// mid = (???)

// (idx / row_sz) => row_idx
// (idx % row_sz) => col_idx

// 5 / 4 => 1
// 5 % 4 => 1


////////////////////////////////////////////////////////////

// Final Solution
// Time: O(log(N * M))
// Space: O(1)

pair<int,int> get2DIndex(int idx, int col_sz) {
  return { 
    idx / col_sz,
    idx % col_sz
  };
}

bool findTarget(vector<vector<int>>& mat, int target) {
  int row_sz = mat.size();
  int col_sz = mat[0].size();
  int lower_bound = 0;
  int upper_bound = row_sz * col_sz - 1;
  while (lower_bound <= upper_bound) {
    int mid = (upper_bound - lower_bound) / 2 + lower_bound;
    auto [i, j] = get2DIndex(mid, col_sz);
    if (mat[i][j] == target) {
      return true;
    } else if (mat[i][j] < target) {
      lower_bound = mid+1;
    } else {
      upper_bound = mid-1;
    }
  }

  return false;
}


int main() {
  
  vector<vector<int>> mat = {
    {1,3,5,7},
    {10,11,16,20},
    {23,30,34,60}
  };

  int target = 65;

  bool found = findTarget(mat, target);
  if (found) {
    cout << "Value Found" << endl;
  } else {
    cout << "Value Not Found" << endl;
  }

  return 0;
}
