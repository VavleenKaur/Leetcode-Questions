class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n = pushed.size(), i=0, j=0;
        while(i<n && j<n){
            while(i<n && j<n && pushed[i]!=popped[j]){
                s.push(pushed[i++]);
            }
            if(i<n && j<n && pushed[i]==popped[j]){
                s.push(pushed[i++]);
            }
            while(j<n && s.size() && popped[j] == s.top()){
                ++j;
                s.pop();
            }
        }
        return s.empty() && i>=n && j>=n; 
    }
};