class Solution {
public:
    bool find132pattern(vector<int>& nums) {
           stack<int> st;
        int n=nums.size();
        int maxx = -1e9;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<maxx ) return true;
            while(st.size() and nums[i] > st.top() ){
                maxx = max(maxx, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
    return false;
    }
};