class Solution {
public:
    
    int longestPalindrome(string s) {
        if(s.size()==1) return 1;
        int len=0;
        unordered_map<char,int>mp;
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
          
        }
        for(auto it:mp)
        {
            if( it.second%2==0 )
            {
                len+=it.second;
            }
            if(it.second%2!=0 && it.second!=1)
            {
                len+=it.second-1;
                char c=it.first;
                mp[c]=1;
            }
        }
        for(auto it:mp)
        {
            if(it.second==1)
            {
                len++;
                break;
            }
        }
        return len;
    }
    
};