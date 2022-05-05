class Solution {
public:
    int f(int ind,int k,vector<int>&coins,vector<vector<int>>&dp)
    {   if(ind==0)
    {
        if(k%coins[0]==0) return k/coins[0];
        else return 1e9;
    }
        if(dp[ind][k]!=-1) return dp[ind][k];
        else
        {
            int notake=f(ind-1,k,coins,dp);
            int take=1e9;
            if(coins[ind]<=k) take=1+f(ind,k-coins[ind],coins,dp);
            return dp[ind][k]=min(notake,take);
        }
    }
    int coinChange(vector<int>& coins, int k) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        for(int j=0;j<=k;j++)
        {
            if(j%coins[0]==0) dp[0][j]=j/coins[0];
            else dp[0][j]=1e9;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                int notake=dp[i-1][j];
                int take=1e9;
                if(coins[i]<=j) take=1+dp[i][j-coins[i]];
                dp[i][j]=min(notake,take);
            }
        }
        int ans=dp[n-1][k];
        if(ans>=1e9) return -1;
        else return ans;
    }
};