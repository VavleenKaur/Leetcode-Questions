class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n<=1)
        {
            return n?cost[0]:0;
        }
        vector<int>dp(n,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++)
        {
            int f_step=dp[i-1]+cost[i];
            int s_step=dp[i-2]+cost[i];
            dp[i]=min(f_step,s_step);
        }
        return min(dp[n-1],dp[n-2]);
    }
    // int memo(vector<int>& cost,int ind)
    // {
    //    if(ind==0 || ind==1) return cost[ind];
    //     int oneStep=0,twoStep=0;
    //     oneStep=memo(cost,ind-1)+abs(cost[ind]);
    //     twoStep=memo(cost,ind-2)+abs(cost[ind]);
    //     return min(oneStep,twoStep);
    // }
};