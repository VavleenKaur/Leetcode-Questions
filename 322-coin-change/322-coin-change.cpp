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
        vector<int>prev(k+1,0);
        for(int j=0;j<=k;j++)
        {
            if(j%coins[0]==0) prev[j]=j/coins[0];
            else prev[j]=1e9;
        }
        for(int i=1;i<n;i++)
        {  vector<int> cur(k+1,0);
            for(int j=0;j<=k;j++)
            {
                int notake=prev[j];
                int take=1e9;
                if(coins[i]<=j) take=1+cur[j-coins[i]];
                cur[j]=min(notake,take);
            }
         prev=cur;
        }
        int ans=prev[k];
        if(ans>=1e9) return -1;
        else return ans;
    }
};