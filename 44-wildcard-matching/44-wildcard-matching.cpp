class Solution {
public:
    
    bool isMatch(string s, string p) {
       int n=s.size();
        int m=p.size();
	vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
	dp[0][0]=true;
	for(int j=1;j<=m;j++)
	{
        bool flg=true;
		for(int a=1;a<=j;a++)
            {
                if(p[a-1]!='*')
                {
                    flg=false;
					break;
                }
            }
		dp[0][j]=flg;

	}
	for(int i=1;i<=n;i++)
	{  dp[i][0]=false;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i-1]==p[j-1] || p[j-1]=='?') {
				dp[i][j]=dp[i-1][j-1];}
        else if(p[j-1]=='*') 
		{dp[i][j]= dp[i-1][j] | dp[i][j-1];}
        else {dp[i][j]= false;}
		}
	}
     return dp[n][m];
    }
};