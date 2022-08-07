class Solution {
public:
   
    int mod=1e9+7;
     long long int memo(vector<vector<int>>&dp, long long int ind, char pv, long long int len)
    {   int prev=int(pv);
        if(ind==len) return 1;
        if(dp[ind][prev]!=-1) return dp[ind][prev]%mod;
        if(pv=='\0')
        {
            return dp[ind][prev]=(memo(dp,ind+1,'a',len)+memo(dp,ind+1,'e',len)+memo(dp,ind+1,'i',len)+memo(dp,ind+1,'o',len)+memo(dp,ind+1,'u',len))%mod;
        }
        else if(pv=='a')
        {   cout<<prev<<ind;
            return dp[ind][prev]=(memo(dp,ind+1,'e',len))%mod;
        }
        else if(pv=='e')
        {
            return dp[ind][prev]=(memo(dp,ind+1,'a',len)+memo(dp,ind+1,'i',len))%mod;
        }
        else if(pv=='i')
        {
            return dp[ind][prev]=(memo(dp,ind+1,'a',len)+memo(dp,ind+1,'e',len)+memo(dp,ind+1,'o',len)+memo(dp,ind+1,'u',len))%mod;
        }
        else if(pv=='o')
        {
            return dp[ind][prev]=(memo(dp,ind+1,'i',len)+memo(dp,ind+1,'u',len))%mod;
        }
        else if(pv=='u')
        {
            return dp[ind][prev]=(memo(dp,ind+1,'a',len))%mod;
        }
        else
        {
            return dp[ind][prev]=0;
        }
        
    }
    
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n+1,vector<int>(256,-1));
        return memo(dp,0,'\0',n)%mod;
    }
};