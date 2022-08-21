class Solution {
public:
    void findCombination(int ind,vector<int>c,int t,vector <vector<int>> &ans,vector<int> v)
    {   if(ind==c.size())
    {if(t==0)
        {ans.push_back(v);}
     return;
    }
        
        if(t>=c[ind])
        { v.push_back(c[ind]);
            findCombination(ind,c,t-c[ind],ans,v);
            v.pop_back();
        }
         findCombination(ind+1,c,t,ans,v);
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector <vector<int>> ans;
        vector <int> v;
        findCombination(0,c,t,ans,v);
        return ans;
    }
};