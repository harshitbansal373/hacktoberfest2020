// Link to the problem : https://leetcode.com/problems/number-of-islands/submissions/
// Problem Name : Number of islands
// Solution Method : Depth First Search (DFS)

class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '2';
        if(i > 0) {
            if(grid[i-1][j] == '1')
                dfs(grid,i-1,j);
        }
        if(j < grid[i].size() - 1) {
            if(grid[i][j+1] == '1')
                dfs(grid,i,j+1);
        }
        if(i < grid.size() - 1) {
            if(grid[i+1][j] == '1')
                dfs(grid,i+1,j);
        } 
        if(j > 0) {
            if(grid[i][j-1] == '1')
                dfs(grid,i, j-1);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0;i < grid.size(); i++) {
            for(int j = 0;j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid,i,j);
                }
            } 
        }
        return count;
    }
    
};
