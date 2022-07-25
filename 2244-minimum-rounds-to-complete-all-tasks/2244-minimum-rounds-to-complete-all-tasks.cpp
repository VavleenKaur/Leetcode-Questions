class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>m;
        for(int i=0;i<tasks.size();i++)
        {
            m[tasks[i]]++;
        }
        int rounds=0;
        for(auto c:m)
        {
            if(c.second<2)
            {
                return -1;
            }
            else if(c.second==2)
            {
               rounds++; 
            }
            else
            {   if(c.second % 3 ==1)
                {int r=(c.second/3);
                 int q=c.second - r*3;
                 rounds=rounds+r+(q%2);
                }
                else
                {  int r=(c.second/3);
                   if(c.second % 3 ==2)rounds=rounds+r+1; 
                   else
                   {
                       rounds+=r;
                   }
                }
            }
        }
        return rounds;
    }
};