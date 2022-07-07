class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)return n;
        int prev2=0,prev=1;
        for(int i=2; i<=n; i++){
            int curr = prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
        
    }
    // int fibo(int n,vector<int>&dp)
    // {
    //     if(n<=1) return dp[n]=n;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=fib(n-1)+fib(n-2);
    // }
};