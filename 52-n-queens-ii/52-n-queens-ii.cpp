class Solution {
public:
    void rec(int col, int n,vector<string>&board,int &ans,vector<int>&left,vector<int>&upleftdiag,vector<int>&downleftdiag)
    {
        if(col==n)
        {
            ans++;
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(board[row][col]=='.' && left[row]==0 && upleftdiag[row+col]==0 && downleftdiag[n-1+col-row]==0)
            {
                board[row][col]='Q';
                left[row]=1; 
                upleftdiag[row+col]=1;
                downleftdiag[n-1+col-row]=1; rec(col+1,n,board,ans,left,upleftdiag,downleftdiag);
                board[row][col]='.';
                left[row]=0; 
                upleftdiag[row+col]=0;
                downleftdiag[n-1+col-row]=0;
            }
        }
    }
    int totalNQueens(int n) {
        string s(n,'.');
        vector<string>board(n,s);
        int ans=0;
        vector<int>left(n,0);
        vector<int>upleftdiag(2*n-1,0),downleftdiag(2*n-1,0);
        rec(0,n,board,ans,left,upleftdiag,downleftdiag);
        return ans;
    }
};