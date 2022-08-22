class Solution {
public:
    void rec(int index,string s, vector<vector<string>>&res,vector<string>&v)
    {
        if(index==s.size()) 
        {
            res.push_back(v);
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                v.push_back(s.substr(index,i-index+1));
                rec(i+1,s,res,v);
                v.pop_back();
            }
        }
        
    }
    bool isPalindrome(string s, int start,int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>v;
        rec(0,s,res,v);
        return res;
    }
};