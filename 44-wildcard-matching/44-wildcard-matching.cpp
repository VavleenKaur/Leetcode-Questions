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
        vector<vector<bool>>dp(lens+1,vector<bool>(lenp+1,false));
        dp[0][0]=true;
        for(int indp=1;indp<=lenp;indp++)
        {   bool flag=true;
            for(int i=1;i<=indp;i++)
            {
                if(p[i-1]!='*')
                {
                    flag= false;
                    break;
                }
            }
            dp[0][indp]=flag;
        }
        for(int inds=1;inds<=lens;inds++)
        {
            for(int indp=1;indp<=lenp;indp++)
             { 
                if(s[inds-1]==p[indp-1] || p[indp-1]=='?')
              {
                 dp[inds][indp]=dp[inds-1][indp-1];
              }
               else if(p[indp-1]=='*')
              {
                dp[inds][indp]=dp[inds][indp-1] | dp[inds-1][indp];
              }
            }
        }
        return dp[lens][lenp];
    }
};