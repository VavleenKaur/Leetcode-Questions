class Solution {
public:
    
    void findCombination(int index,vector<int>c,int t,vector<vector<int>>&ans,vector<int>v)
    {
            if(t==0)
            { 
                ans.push_back(v);
                return;
            }
            
        
        for(int i=index;i<c.size();i++)
        {
            if(i>index && c[i]==c[i-1])
            {
                continue;
                //remove duplicates
                // only select first index in recursion tree then check duplicates
            }
            if(c[i]>t)
            {
                break;
                // as already sorted
            }
            v.push_back(c[i]);
            findCombination(i+1,c,t-c[i],ans,v);
            v.pop_back();
        }
        /*
        findCombination(index+1,c,t,ans,v);*/
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        vector<vector<int>> ans;
        vector<int> v;
        findCombination(0,c,t,ans,v);
        return ans;
    }
};