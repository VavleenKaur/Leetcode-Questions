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
        vector<bool>dp(s.size()+1,false);
         dp[s.size()]=true;
        for(int i=s.size()-1;i>=0;i--)
        {
            for(int j=i;j<s.size();j++)
            { 
                 string str=s.substr(i,j-i+1);
            if(st.find(str)!=st.end())
            {
               
               dp[i]=(dp[i] | dp[j+1]);
                
            }
                
            }
           
           
        }
        return dp[0];
    }
};