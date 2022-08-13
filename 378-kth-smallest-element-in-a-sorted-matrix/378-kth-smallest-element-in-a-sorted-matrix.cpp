class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low=matrix[0][0];
        int n=matrix.size();
        int high=matrix[n-1][n-1];
        int count=0,ans;
        while(low<=high)
        {
            int mid=(low+(high-low)/2);
            int i=0,j=n-1;
            count=0;
            while(i<n && j>=0)
            {
                if(mid>=matrix[i][j])
                {
                    count+=j+1;
                    i++;
                }
                else
                {
                    j--;
                }
            }
            if(count>=k)
            {
                high=mid-1;
                ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};