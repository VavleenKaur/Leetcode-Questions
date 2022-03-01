class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>count;
        for(int i=0;i<=n;i++)
        {
           count.push_back(__builtin_popcount(i));
        }
        return count;
        
    }
};