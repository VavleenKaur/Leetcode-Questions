class Solution {
public:
    // int memo(vector<int>&cost,int ind,vector<int>&dp)
    // {
    //     if(ind<1) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int mincost=1e9;
    //     mincost=min(cost[ind-1]+memo(cost,ind-1,dp),cost[ind-1]+memo(cost,ind-2,dp));
    //     return dp[ind]=mincost;
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+2,0);
        int mincost=1e9;
        for(int ind=2;ind<(n+2);ind++)
        {
            
        mincost=min(cost[ind-2]+dp[ind-1],cost[ind-2]+dp[ind-2]);
        cout<<mincost;
        dp[ind]=mincost;
        }
       return min(dp[n+1],dp[n]);
    }
};