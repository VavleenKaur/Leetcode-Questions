class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,int>mp_s;
        unordered_map<char,int>mp_pt;
        
        stringstream iss(s);
        int i=0;
        string word;
        for(word;iss>>word;i++)
        {
            if(i==pattern.size()||mp_s[word]!=mp_pt[pattern[i]])
            {
                return false;
            }
            mp_s[word]=mp_pt[pattern[i]]=i+1;
        }
        return i==pattern.size();
    }
};