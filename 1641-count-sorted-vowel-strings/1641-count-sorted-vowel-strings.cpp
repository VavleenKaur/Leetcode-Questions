class Solution {
public:
    
    int memo(int n,char last_char,vector<vector<int>>&dp)
    {
        if(n==0) return 1;
        if(dp[n][int(last_char)]!=-1) return dp[n][int(last_char)];
        if(last_char=='\0')
        {
            return dp[n][int(last_char)]=(memo(n-1,'a',dp)+memo(n-1,'e',dp)+memo(n-1,'i',dp)+memo(n-1,'o',dp)+memo(n-1,'u',dp));
        }
        else if(last_char=='a')
        {
            return dp[n][int(last_char)]=memo(n-1,'a',dp);
        }
        else if(last_char=='e')
        {
            return dp[n][int(last_char)]=memo(n-1,'a',dp)+memo(n-1,'e',dp);
        }
        else if(last_char=='i')
        {
            return dp[n][int(last_char)]=memo(n-1,'a',dp)+memo(n-1,'e',dp)+memo(n-1,'i',dp);
        }
        else if(last_char=='o')
        {
            return dp[n][int(last_char)]=(memo(n-1,'a',dp)+memo(n-1,'e',dp)+memo(n-1,'i',dp)+memo(n-1,'o',dp));
        }
        else if(last_char=='u')
        {
            return dp[n][int(last_char)]=(memo(n-1,'a',dp)+memo(n-1,'e',dp)+memo(n-1,'i',dp)+memo(n-1,'o',dp)+memo(n-1,'u',dp));
        }
        else return dp[n][int(last_char)]=0;
        
    }
    int countVowelStrings(int n) {
        if(n==1) return 5;
        vector<vector<int>>dp(n+1,vector<int>(257,-1));
       return memo(n,'\0',dp);
    }
};