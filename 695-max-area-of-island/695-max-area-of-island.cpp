class Solution {
public:
    int findArea(vector<vector<int>>& grid,int i,int j,int &area)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size())
        {
            return 0;
        }
        if(grid[i][j]==0)
        {
            return 0;
        }
        area++;
        grid[i][j]=0;
        findArea(grid,i+1,j,area);
        findArea(grid,i-1,j,area);
        findArea(grid,i,j+1,area);
        findArea(grid,i,j-1,area);
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0,area=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {    area=0;
                if(grid[i][j]==1)
                {   
                    res=max(res,findArea(grid,i,j,area));
                }
                
            }
        }
        
        return res;
    }
};