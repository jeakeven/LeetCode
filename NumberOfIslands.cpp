/*

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000

Answer: 1

Example 2:

11000
11000
00100
00011

Answer: 3

*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        grid[i][j] = '0';
        if(i > 0 && grid[i-1][j] == '1') {
            dfs(grid, i - 1, j);
        }
        if(i < m - 1 && grid[i+1][j] == '1') {
            dfs(grid, i + 1, j);
        }
        if(j > 0 && grid[i][j-1] == '1') {
            dfs(grid, i, j - 1);
        }
        if(j < n - 1 && grid[i][j+1] == '1') {
            dfs(grid, i, j + 1);
        }
    }
};