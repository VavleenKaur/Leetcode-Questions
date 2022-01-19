class Solution {
public:
    void findCombination(int index,vector<int>c,int t,vector <vector<int>> &ans,vector<int> v)
    {
        if(index==c.size())
        {
            if(t==0)
            {
                ans.push_back(v);
            }
            return;
        }
        
        if(c[index]<=t)
        {   
            v.push_back(c[index]);
            findCombination(index,c,t-c[index],ans,v);
            v.pop_back();
        }
        findCombination(index+1,c,t,ans,v);
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector <vector<int>> ans;
        vector <int> v;
        int index=0;
        findCombination(index,c,t,ans,v);
        return ans;
    }
};