class Solution {
public:
    static bool comp(string &a, string &b)
    {
        return (a.size()<b.size());
    }
    bool isAllowed(string &curr, string &prevv)
    {
        if(curr.size()!=prevv.size()+1) return false;
        //string matching
        int currL=curr.size();
        int i=0,j=0;
        while(i<currL)
        {
            if(curr[i]==prevv[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
     return  (i==currL && j==prevv.size());
    }
    int longestStrChain(vector<string>& words) {
       sort(words.begin(),words.end(),comp);
        if(words.size()<=1) return words.size();
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=1;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(isAllowed(words[i],words[prev]))
                {
                    if(dp[prev]+1>dp[i])
                    {
                        dp[i]=dp[prev]+1;
                    }
                }
            }
            maxi=dp[i]>maxi?dp[i]:maxi;
        }
        return maxi;
    }
};