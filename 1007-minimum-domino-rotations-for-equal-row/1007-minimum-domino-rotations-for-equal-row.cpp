class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int>t(6,0);
        vector<int>b(6,0);
        for(int i=0;i<tops.size();i++)
        {
            t[tops[i]-1]++;
            b[bottoms[i]-1]++;
        }
        int maxm=0;
        bool flag=false;
        if(*max_element(t.begin(),t.end())<=(*max_element(b.begin(),b.end())))
        { 
            t=b;
            flag=true;
        }
        maxm=max_element(t.begin(),t.end())-t.begin();
        maxm++;
        int count=0;
        if(flag)
        {
            for(int i=0;i<bottoms.size();i++)
            {
                if(bottoms[i]!=maxm && tops[i]==maxm)
                {
                    count++;
                }
                else if(bottoms[i]!=maxm && tops[i]!=maxm)
                {
                    return -1;
                }
            }
        }
        else
        {
            for(int i=0;i<tops.size();i++)
            {
                if(tops[i]!=maxm && bottoms[i]==maxm)
                {
                    count++;
                }
                else if(bottoms[i]!=maxm && tops[i]!=maxm)
                {
                    return -1;
                }
            }
        }
        return count;
        
    }
};