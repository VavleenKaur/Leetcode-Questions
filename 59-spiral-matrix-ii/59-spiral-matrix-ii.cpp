class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int i=0,j=0,c=1;
        while( i>=0 && j>=0 && i<n && j<n && !matrix[i][j] )
        {right(matrix,n,i,j,c);
          bottom(matrix,n,i,j,c);
         left(matrix,n,i,j,c);
        top(matrix,n,i,j,c);
        }
        return matrix;
    }
    void right(vector<vector<int>>&matrix,int n,int &i,int &j,int &c)
    {  
        while(j<n && j>=0 && !matrix[i][j])
        {
            matrix[i][j]=c++;
            j++;
        }
        i++;
        j--;
    }
    void bottom(vector<vector<int>>&matrix,int n,int &i,int &j,int &c)
    {
        while(i<n && i>=0 && !matrix[i][j])
        {
            matrix[i][j]=c++;
            i++;
        }
        j--;
        i--;
    }
    void left(vector<vector<int>>&matrix,int n,int &i,int &j,int &c)
    {
       while(j<n && j>=0 && !matrix[i][j])
        {
            matrix[i][j]=c++;
            j--;
        }
        i--;
        j++;
    }
    void top(vector<vector<int>>&matrix,int n,int &i,int &j,int &c)
    {
        while(i<n && i>=0 && !matrix[i][j])
        {
            matrix[i][j]=c++;
            i--;
        }
        j++;
        i++;
    }
};