class Solution {
public:
    
    int f(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        int mini=1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind=i;ind<=j;ind++)
        {
            int cost=cuts[j+1]-cuts[i-1]+f(i,ind-1,cuts,dp)+f(ind+1,j,cuts,dp);
            mini=min(cost,mini);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n); //5
        cuts.insert(cuts.begin(),0); //6
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));// 0 1 3 4 5 7
        for(int i=c;i>=1;i--)
        {   
            for(int j=1;j<=c;j++)
            {   if(i>j) continue;
                int mini=1e9;
               for(int ind=i;ind<=j;ind++)
        {
            int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
            mini=min(cost,mini);
        } 
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
};