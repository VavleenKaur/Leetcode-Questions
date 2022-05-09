// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int f(int ind,int buy,int k,int A[],vector<vector<vector<int>>>&dp,int n)
{   if(ind==n || k==0) return 0;
    if(dp[ind][buy][k]!=-1) return dp[ind][buy][k];
    if(buy)
    {
        return dp[ind][buy][k]=max(-A[ind]+f(ind+1,0,k,A,dp,n),f(ind+1,1,k,A,dp,n));
    }
    else
    {
        return dp[ind][buy][k]=max(A[ind]+f(ind+1,1,k-1,A,dp,n),f(ind+1,0,k,A,dp,n));
    }
}
class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        
      vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(2,vector<int>(K+1,-1)));
      return f(0,1,K,A,dp,N);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends