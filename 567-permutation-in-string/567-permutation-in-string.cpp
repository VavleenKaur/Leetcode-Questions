class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //sliding window
        vector<int>s1_freq(26,0),s2_freq(26,0);
        for(int i=0;i<s1.size();i++)
        {
            s1_freq[s1[i]-'a']++;
        }
        
        int start=0,end=0;
        while(end<s2.size())
        {
            s2_freq[s2[end]-'a']++;
            if(end-start+1==s1.size())
            {
                if(s1_freq==s2_freq)
                {
                    return true;
                }
                else
                {   s2_freq[s2[start]-'a']--;
                    start++;
                    end++;
                    
                }
                
            }
            if(end-start+1<s1.size())
                {
                    end++;
                }
            
            
        }
        return false;
        
    }
};