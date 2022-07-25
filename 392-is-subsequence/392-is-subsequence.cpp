class Solution {
public:
    bool memo(int inds,int indt,string s, string t,vector<vector<int>>&dp)
    {
        if(inds==0) return true;
        if(inds>=1 && indt==0) return false;
        if(dp[inds][indt]!=-1) return dp[inds][indt];
        if(s[inds-1]==t[indt-1]) return dp[inds][indt]=memo(inds-1,indt-1,s,t,dp);
        else
        {
            return dp[inds][indt]=memo(inds,indt-1,s,t,dp);
        }
    }
    bool isSubsequence(string s, string t) {
        int lens=s.size();
        int lent=t.size();
        vector<vector<int>>dp(lens+1,vector<int>(lent+1,-1));
        return memo(lens,lent,s,t,dp);
    }
};