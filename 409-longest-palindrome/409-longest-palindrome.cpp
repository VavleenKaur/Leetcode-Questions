class Solution {
public:
    
    int longestPalindrome(string s) {
        if(s.size()==1) return 1;
        int len=0;
        unordered_map<char,int>mp;
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]%2==0)
            {  len+=mp[s[i]];
                mp[s[i]]=0;
            }
        }
        for(auto it:mp)
        {
            if( it.second==1 )
            {
                len++;
                return len;
            }
        }
        return len;
    }
    
};