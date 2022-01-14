class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
       unordered_map<int,int>m;
        int count=0;
        for(int i=0;i<time.size();i++)
        {
           if(time[i]%60!=0)
           {
               count+=m[60-(time[i]%60)];
           }
            else
            {
                count+=m[0];
            }
           m[time[i]%60]++;
           
        }
        
        return count;
    }
};