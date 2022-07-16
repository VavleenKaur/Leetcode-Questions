class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int lens=s.size();
        int lent=t.size();
        vector<vector<int>>dp(lens+1,vector<int>(lent+1,0));
        for(int inds=1;inds<=lens;inds++)
        {
            for(int indt=1;indt<=lent;indt++)
            {
                if(s[inds-1]==t[indt-1])
                {
                    dp[inds][indt]=1+dp[inds-1][indt-1];
                }
                else
                {
                    dp[inds][indt]=max(dp[inds-1][indt],dp[inds][indt-1]);
                }
            }
        }
        int i=lens,j=lent;
        string res="";
        while(i!=0 && j!=0)
        {
            if(s[i-1]==t[j-1])
            {
                res+=s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                res+=s[i-1];
                i--;
            }
            else
            {
                res+=t[j-1];
                j--;
            }
        }
        while(i!=0)
        {
            res+=s[i-1];
                i--;
        }
        while(j!=0)
        {
             res+=t[j-1];
                j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};