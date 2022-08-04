class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, int m, int n)
    {
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]!='1') return;
        grid[row][col]='2';
        
        dfs(grid,row+1,col,m,n);
        dfs(grid,row-1,col,m,n);
        dfs(grid,row,col+1,m,n);
        dfs(grid,row,col-1,m,n);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};