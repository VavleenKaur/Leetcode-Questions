class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int count=0;
        for(auto n:m)
        {   int nm=n.first,c=n.second;
            if(nm ==k-nm) count+=(c)/2;
            else if(m.count(k-nm))
            {   
                int minm=min(c,m[k-nm]);
                count+=minm;
                m[nm]-=minm;
                m[k-nm]-=minm;
            }
        }
        return count;
    }
};