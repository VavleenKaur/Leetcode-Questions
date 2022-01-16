class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int pref_0=-1,suf_0=-1,max_0=-1,zero=0;
        for(int i=0;i<seats.size();i++)
        {
            if(seats[i]==0)
            {
                zero++;
            }
            else
            {
                if(pref_0==-1)
                {
                    pref_0=zero;
                }
                else
                {
                    max_0=max(max_0,zero);
                }
                zero=0;
            }
            
        }
        suf_0=zero;
        
        max_0=max(max(pref_0,suf_0),(max_0+1)/2);
        return max_0;
    }
};