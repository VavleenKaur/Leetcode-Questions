class Solution {
public:
    bool memo(string &s, string &p,int inds, int indp,vector<vector<int>>&dp)
    {   if(inds==0 && indp==0) return true;
        if(indp==0) return false;
        if(inds==0) 
        {
            for(int i=1;i<=indp;i++)
            {
                if(p[i-1]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        
        if(dp[inds][indp]!=-1) return dp[inds][indp];
        if(s[inds-1]==p[indp-1] || p[indp-1]=='?')
        {
            return dp[inds][indp]=memo(s,p,inds-1,indp-1,dp);
        }
        else if(p[indp-1]=='*')
        {
            return dp[inds][indp]=memo(s,p,inds,indp-1,dp)| memo(s,p,inds-1,indp,dp);
        }
        else 
        {
            return dp[inds][indp]=false;
        }
        
    }
    bool isMatch(string s, string p) {
        int lens=s.size();
        int lenp=p.size();
        vector<vector<int>>dp(lens+1,vector<int>(lenp+1,-1));
        return memo(s,p,lens,lenp,dp);
    }
};