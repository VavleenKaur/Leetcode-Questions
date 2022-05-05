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
        int ans=f(n-1,k,coins,dp);
        if(ans>=1e9) return -1;
        else return ans;
    }
};