class Solution {
public:
    
    
    void sol(int col,vector<vector<string>>&ans,vector<string>&board,vector<int>&leftRow,vector<int>&lowerDiag,vector<int>&upperDiag,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftRow[row]==0 && lowerDiag[row+col]==0 && upperDiag[n-1+col-row]==0)
            {
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiag[row+col]=1;
                upperDiag[n-1+col-row]=1;
                sol(col+1,ans,board,leftRow,lowerDiag,upperDiag,n);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiag[row+col]=0;
                upperDiag[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
           board[i]=s;
        }
        vector<int>leftRow(n,0);
        vector<int>lowerDiag(2*n-1,0);
        //sum of row and col index 0-2n-1
        vector<int>upperDiag(2*n-1,0);
        sol(0,ans,board,leftRow,lowerDiag,upperDiag,n);
        return ans;
    }
};