class Solution {
public:
   
        vector<string> ans;
    vector<string> arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(string x, string fin, int n, int i){
            if(i == n){
                if(!n){
                    return;
                }
                ans.push_back(fin);
            }
        for(int j = i; j<x.size(); j++){
            int t = x[j] - '0';
            for(int k = 0; k<arr[t].size(); k++){
                solve(x, fin+arr[t][k], n, i+1);
            }
            return;
        }
        
    }  
    vector<string> letterCombinations(string digits) {      
        solve(digits, "", digits.size(), 0);
        return ans;
    }
};
    