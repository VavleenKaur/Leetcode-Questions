class Solution {
public:
    int rec(int col, int n,vector<string>&board,vector<int>&left,vector<int>&upleftdiag,vector<int>&downleftdiag)
    {
        if(col==n)
        {
            return 1;
        }
        int res=0;
        for(int row=0;row<n;row++)
        {
            if(board[row][col]=='.' && left[row]==0 && upleftdiag[row+col]==0 && downleftdiag[n-1+col-row]==0)
            {
                board[row][col]='Q';
                left[row]=1; 
                upleftdiag[row+col]=1;
                downleftdiag[n-1+col-row]=1; res+=rec(col+1,n,board,left,upleftdiag,downleftdiag);
                board[row][col]='.';
                left[row]=0; 
                upleftdiag[row+col]=0;
                downleftdiag[n-1+col-row]=0;
            }
        }
        return res;
    }
    int totalNQueens(int n) {
        string s(n,'.');
        vector<string>board(n,s);
        vector<int>left(n,0);
        vector<int>upleftdiag(2*n-1,0),downleftdiag(2*n-1,0);
       return  rec(0,n,board,left,upleftdiag,downleftdiag);
      
    }
};