class Solution {
public:
    int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        map<long,long>mp;
        mp[arr[0]]=1;
        for(int i=1;i<arr.size();i++)
        {
            mp[arr[i]]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    if(find(arr.begin(),arr.end(),arr[i]/arr[j])!=arr.end())
                    {
                        mp[arr[i]]+=mp[arr[j]]*mp[arr[i]/arr[j]];
                    }
                }
            }
        }
        long count=0;
        for(auto it:mp)
        {
            count=(count+it.second)%mod;
        }
        return count%mod;
    }
};