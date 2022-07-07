class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)return n;
vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
 return dp[n];
        
    }
    // int fibo(int n,vector<int>&dp)
    // {
    //     if(n<=1) return dp[n]=n;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=fib(n-1)+fib(n-2);
    // }
};