class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++)
        {
            int fs=dp[i-1]+cost[i];
            int ss=dp[i-2]+cost[i];
            dp[i]=min(fs,ss);
        }
        return min(dp[n-1],dp[n-2]);
        }
};