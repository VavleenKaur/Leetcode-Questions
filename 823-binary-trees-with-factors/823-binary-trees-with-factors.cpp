class Solution {
public:
    int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        map<long,long>mp,ifPresent;
        mp[arr[0]]=1;
        for(int i=0;i<n;i++)
        {
            ifPresent[arr[i]]=1;
        }
        for(int i=1;i<n;i++)
        {
            mp[arr[i]]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    if(ifPresent[arr[i]/arr[j]])
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