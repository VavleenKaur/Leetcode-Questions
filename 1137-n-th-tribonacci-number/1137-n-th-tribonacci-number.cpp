class Solution {
public:
    int f(int ind,vector<int>&dp)
    {
        if(ind==0 || ind==1){
            return ind;
        }
        else if(ind==2) return 1;
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        if(dp[ind]!=0) return dp[ind];
        return dp[ind]=f(ind-1,dp)+f(ind-2,dp)+f(ind-3,dp);
    }
    int tribonacci(int n) {
        vector<int>dp(n+1,0);
        return f(n,dp);
    }
};