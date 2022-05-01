class Solution {
public:
    int f(int i,int j, vector<vector<int>>& triangle,int n,vector<vector<int>>&dp)
    {
        if(i==n-1) return dp[i][j]=triangle[i][j];
        else if(dp[i][j]!=-1) return dp[i][j];
        else
        {
            int down=triangle[i][j]+f(i+1,j,triangle,n,dp);
            int diag=triangle[i][j]+f(i+1,j+1,triangle,n,dp);
            return dp[i][j]=min(down,diag);
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++) {dp[n-1][j]=triangle[n-1][j];}
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
               
                int down=0,diag=0;
                down+=triangle[i][j]+dp[i+1][j];
                diag+=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diag);
                
            }
        }
        return dp[0][0];
        
    }
};