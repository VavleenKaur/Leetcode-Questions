class Solution {
public:
    int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp,int n)
    {   if(ind>=n) return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy)
        {
            return dp[ind][buy]=max((-prices[ind]+f(ind+1,0,prices,dp,n)),(f(ind+1,1,prices,dp,n)));
       }
        else
         {
            return dp[ind][buy]=max(prices[ind]+f(ind+2,1,prices,dp,n),f(ind+1,0,prices,dp,n));      
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return f(0,1,prices,dp,n);
    }
};