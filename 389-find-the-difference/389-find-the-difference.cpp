class Solution {
public:
    char findTheDifference(string s, string t) {
       int ans=0;
        for(auto &c:t)
        {
            ans+=c;
        }
        for(auto &c:s)
        {
            ans-=c;
        }
        return char(ans);
    }
};