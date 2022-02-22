class Solution {
public:
    bool isPalindrome(string s) {
        string pal;
        for(int i=0;i<s.length();i++)
        {   
            if((s[i]>=65 && s[i]<=90)||(s[i]>=48 && s[i]<=57))
            {   
                pal+=tolower(s[i]);
            }
             if((s[i]>=97 && s[i]<=122))
            {   
                pal+=(s[i]);
            }
        }
        string pal_rev=pal;
        reverse(pal.begin(),pal.end());
        if(pal_rev!=pal)
        {
            return false;
        }
        return true;
    }
};