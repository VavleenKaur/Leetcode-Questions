class Solution {
public:
    
    void dfs(vector<vector<bool>>& ocean, vector<vector<int>>& heights,int x, int y, int prev, int m ,int n)
    {   
        if(x<0 || y<0 || x>=m || y>=n || ocean[x][y] || heights[x][y]<prev) return;
        ocean[x][y]=true;
        dfs(ocean,heights,x+1,y,heights[x][y],m,n);
        dfs(ocean,heights,x-1,y,heights[x][y],m,n);
        dfs(ocean,heights,x,y+1,heights[x][y],m,n);
        dfs(ocean,heights,x,y-1,heights[x][y],m,n);
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        int m=heights.size();
        int n=heights[0].size();
        if(m<1 || n<1) return ans;
        
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
        
        for(int j=0;j<n;j++)
        {
            dfs(pacific,heights,0,j,INT_MIN,m,n);
            dfs(atlantic,heights,m-1,j,INT_MIN,m,n);
        }
        for(int i=0;i<m;i++)
        {
            dfs(pacific,heights,i,0,INT_MIN,m,n);
            dfs(atlantic,heights,i,n-1,INT_MIN,m,n);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j]==atlantic[i][j] && pacific[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};