class Solution {
public:
    bool memo(int inds,int indt,string s, string t)
    {
        if(inds<0) return true;
        if(inds>=0 && indt<0) return false;
        if(s[inds]==t[indt]) return memo(inds-1,indt-1,s,t);
        else
        {
            return memo(inds,indt-1,s,t);
        }
    }
    bool isSubsequence(string s, string t) {
        int lens=s.size();
        int lent=t.size();
        return memo(lens-1,lent-1,s,t);
    }
};