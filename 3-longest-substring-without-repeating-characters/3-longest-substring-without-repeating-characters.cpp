class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
        {
            return 0;
        }
       int i=0,j=0;
        vector <int> count(300,0);
        count[s[i]]++;
        int res=1;
        while(j<s.length()-1)
        {
            if(count[s[j+1]]==0)
            {  
                j++;
                count[s[j]]++;
                res=max(res,j-i+1);
                
            }
            else
            {
                count[s[i]]--;
                i++;
            }
        }
        return res;
    }
};