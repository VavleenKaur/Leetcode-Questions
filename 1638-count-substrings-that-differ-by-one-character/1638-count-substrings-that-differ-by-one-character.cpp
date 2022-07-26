class Solution {
public:
    int countSubstrings(string s, string t) {
        int lens=s.size();
        int lent=t.size();
        int ans=0;
        for(int i=0;i<lens;i++)
        {
            for(int j=0;j<lent;j++)
            {
                int x=i;
                int y=j;
                int diff=0;
                while(x<lens && y<lent)
                {   if(s[x]!=t[y]) diff++;
                    if(diff==1) ans++;
                    if(diff==2) break;
                    x++;
                    y++;
                }
            }
        }
        return ans;
    }
};