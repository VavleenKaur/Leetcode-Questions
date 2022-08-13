class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ele=matrix[0][n-1];
        int i=0,j=n-1;
        if(ele==target) return true;
        while(i<m && j>=0)
        {
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};