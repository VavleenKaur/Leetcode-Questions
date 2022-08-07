class Solution {
public:
vector <vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(vector<vector<int>>& grid, int i, int j ,int m , int n, bool &flag)
    {    if(i<0 || i>=m || j<0 || j>=n)
        {   flag=false;
            return;
        }
        if(grid[i][j]!=0) return;
        grid[i][j]=2;
        for(auto x:dir)
        {
            dfs(grid,i+x[0],j+x[1],m,n,flag);
        }
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        bool flag=true;
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                flag=true;
                if(grid[i][j]==0)
                {
                    dfs(grid,i,j,m,n,flag);
                    if(flag==true) count++;
                }
            }
        }
        return count;
    }
};