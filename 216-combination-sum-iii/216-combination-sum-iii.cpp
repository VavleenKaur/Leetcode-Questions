class Solution {
public:
    void f(int ind,int t,vector<int>&set,int k,vector<int>&v,vector<vector<int>>&ans)
    {
        if(ind==set.size())
        {
            if(t==0 && v.size()==k)
            {
                ans.push_back(v);
            }
            return;
        }
        if(set[ind]<=t)
        {
            v.push_back(set[ind]);
            f(ind+1,t-set[ind],set,k,v,ans);
            v.pop_back();
            
        }
         f(ind+1,t,set,k,v,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>set(9);
        for(int i=0;i<9;i++)
        {set[i]=i+1;}
        vector<int>v;
        vector<vector<int>>ans;
        f(0,n,set,k,v,ans);
        return ans;
    }
};