class Solution {
public:
    // int rec(int n, vector<int>&dp)
    // {
    //     if(n<=1) return n;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=rec(n-1,dp)+rec(n-2,dp);
    // }
    int fib(int n) {
        if(n<=1)return n;
        int prev1=1,prev2=0,curr=0;
        for(int i=2;i<=n;i++)
        {curr=prev1+prev2;
         prev2=prev1;
         prev1=curr;
        }
        return prev1;
    }
};