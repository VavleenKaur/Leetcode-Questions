class Solution {
public:
    int f(int ind,int tar,vector<int>&coins,vector<vector<int>>&dp)
    {   
        if(ind==0)
        {
            if(tar%coins[ind]==0) return 1;
            return 0;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int notake=f(ind-1,tar,coins,dp);
        int take=0;
        if(coins[ind]<=tar) take=f(ind,tar-coins[ind],coins,dp);
       return  dp[ind][tar]=notake+take;
    }
    int change(int amount, vector<int>& coins) {
       int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        for(int j=0;j<=amount;j++)
        {
            if(j%coins[0]==0) dp[0][j]=1;
            else dp[0][j]=0;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int notake=dp[i-1][j];
                int take=0;
                if(coins[i]<=j) take=dp[i][j-coins[i]];
                dp[i][j]=notake+take;
            }
        }
        return dp[n-1][amount];
    }
};