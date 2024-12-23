// A satellite image of an Ocean consists of green and blue pixels, representing land and water. 
// The Pacific ocean is large, and mostly blue; but contains islands, which are green. 
// Islands themselves may contain blue pixels, which are lakes.
// A frontend presents the image to a user, who can click on it. 
// When the user clicks on a green pixel, a popup will appear that displays the number of lakes in that island. 
// This UI code already exists: the problem of this question is to write the backend function that will return the value to display.

//   A B C D E F G H I J K L M N O P Q R S T
// 0 . . . . . . . . . . . . . . . . . . . .
// 1 . . . . . . . . . . . . . . . . . . . .
// 2 . . X X X . . . . . . . . . . . . . . .
// 3 . . . . . . . . . . . X X X X X X . . .
// 4 . . . . . X X X . . . X . X . . X . . .
// 5 . . . . . X . X . . . X X X X X X . . .
// 6 . . . . . X X X . . . . . . . . . . . .
// 7 . . . . . . . . . . . . . . . . . . . .

  
// Constraints,
// N, M 
// N * M <= 1e9
  
// for given example,
// we have 4 lakes (connected components)

// With DSU, count lakes
// DFS, explore the given island    

// N, M: size of pixel matrix
// i, j: coordinate of pixel clicked

// DFS + DSU
// Pre-processing of: O(alpha(N*M)) ~ O(1)
// Time for backend call: O(N*M)
// Space: O(N*M)


vector<int> P, S;

void dsu_init(int N) {
  P.assign(N+1, -1);
  S.assign(N+1, 1);
  for (int i = 0; i <= N; i++)
     P[i] = i;
}

int root(int x) {
  if (P[x] != x)
      P[x] = root(P[x]);

  return P[x];
}

void union_set(int x, int y) {
  int root_x = root(x);
  int root_y = root(y);
  if (root_x != root_y) {
    if (S[root_x] < S[root_y])
       swap(root_x, root_y);
    
    P[root_y] = root_x;
    S[root_x] += S[root_y];
  }
}

void pre_process_image(vector<vector<char>>& G, int N, int M) {
  dsu_init(N*M);
  
  // left pixel & upper pixel
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (G[i][j] == '.') {
        if (j-1 >= 0 && G[i][j-1] == '.') {
          union_set(left, curr); 
        }
        if(i-1 >= 0 && G[i-1][j] == '.') {
          union_set(top, curr);
        }
      }
    }
  }
}
  
int dfs(int i, int j, vector<vector<char>>& G, int N, int M) {
  if (i < 0 || i == N || j < 0 || j == M)
      return 0;

   if (G[i][j] == '.') {
      root();
   }

  dfs(i+1, j, G, N, M);
  dfs(i-1, j, G, N, M);
  dfs(i, j+1, G, N, M);
  dfs(i, j-1, G, N, M);
}