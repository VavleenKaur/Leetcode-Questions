class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
            unordered_map<int, int> freq;
    int maxi = 0;
    
    for(int i=0; i<nums.size(); i++)
    {
        freq[nums[i]]++;
        maxi = max(maxi, nums[i]);
    }
    
    vector<int> dp(maxi+1);
    
    dp[1] = freq[1];
    
    for(int i=2; i<=maxi; i++)
    {
        dp[i] = max(i*freq[i] + dp[i-2], dp[i-1]);
    }
    
    return dp[maxi];
    
}    

    
};