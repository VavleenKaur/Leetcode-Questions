class Solution {
public:
    int memo(vector<int>&cost,int ind,vector<int>&dp)
    {
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int mincost=1e9;
        mincost=min(cost[ind]+memo(cost,ind-1,dp),cost[ind]+memo(cost,ind-2,dp));
        return dp[ind]=mincost;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(memo(cost,n-1,dp),memo(cost,n-2,dp));
    }
};