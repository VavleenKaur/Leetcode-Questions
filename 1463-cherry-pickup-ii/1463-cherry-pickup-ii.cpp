class Solution {
public:
    int f(int i,int j1,int j2,vector<vector<int>>&grid,int n,int m,vector<vector<vector<int>>>&dp)
    {
        if(j1>m-1 || j1<0 || j2>m-1 || j2<0)
            return -1e8;
        else if(i==n-1)
        {
            if(j1 == j2) return dp[i][j1][j1]=grid[i][j1];
            else return dp[i][j1][j2]= grid[i][j1]+grid[i][j2];
        }
        else if(dp[i][j1][j2]!=-1){return dp[i][j1][j2];}
        else
        {   int maxi=-1e8;
            for(int d1=-1;d1<=1;d1++)
            {
                for(int d2=-1;d2<=1;d2++)
                {
                    if(j1==j2) 
                    {
                        maxi=max(maxi,grid[i][j1]+f(i+1,j1+d1,j2+d2,grid,n,m,dp));
                    }
                    else
                    {
                        maxi=max(maxi,grid[i][j1]+grid[i][j2]+f(i+1,j1+d1,j2+d2,grid,n,m,dp));
                    }
                }
            }
         return dp[i][j1][j2]=maxi;
        }
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
       int  n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
       return f(0,0,m-1,grid,n,m,dp);
    }
};