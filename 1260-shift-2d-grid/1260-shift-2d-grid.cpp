class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int temp=INT_MAX;
        while(k--)
        {
          for(int i=0;i<=m-1;i++)
        {
            for(int j=0;j<=n-1;j++)
            {
               swap(temp,grid[i][j]);
            }
        }
         swap(temp,grid[0][0]);
        }
        return grid;
    }
};