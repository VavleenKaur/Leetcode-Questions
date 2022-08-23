class Solution {
public:
    bool recur(int index, string s, set<string>&st, vector<string>& wordDict,vector<int>&dp)
    {
        if(index==s.size())
            return true;
        if(dp[index]!=-1) return dp[index];
        for(int i=index;i<s.size();i++)
        {  string str=s.substr(index,i-index+1);
            if(st.find(str)!=st.end())
            {
                if(recur(i+1,s,st,wordDict,dp)) return dp[index]=true;
                
            }
        }
        return dp[index]=false;
        
    }
    
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto word:wordDict)
        {
            st.insert(word);
        }
        vector<int>dp(s.size()+1,-1);
        return recur(0,s,st,wordDict,dp);
    }
};