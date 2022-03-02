class Solution {
public:
     bool isSubs(string& s, string& t, int m, int n)
    {
        if(m == s.length())
            return true;
        if(n == t.length())
            return false;
        
        // If last characters of two
        // strings are matching
        if (s[m] == t[n])
            return isSubs(s, t, m + 1, n + 1);
 
        // If last characters are
        // not matching
        return isSubs(s, t, m, n+1);
    }
    
    
    bool isSubsequence(string s, string t) {
        
       if( isSubs(s,t,0,0))
           return true;
        
        return false;
        
    }
};