class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(256,-1);
        int left=0,right=0,len=0;
        while(right<s.size())
        {
            if(freq[s[right]]!=-1)
            {
                left=max(left,freq[s[right]]+1);
            }
            freq[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};