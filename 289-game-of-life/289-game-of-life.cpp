class Solution {
public:
    int valid_cell(int i,int j,int m ,int n,vector<vector<int>>&board,int &count)
    {
        if(i>0 && board[i-1][j])
        {
           count++;
        }
        if(i<m-1 && board[i+1][j])
        {
           count++;
        }
        if(j>0 && board[i][j-1])
        {
           count++;
        }
        if(j<n-1 && board[i][j+1])
        {
           count++;
        }
        if(i<m-1 && j<n-1 && board[i+1][j+1])
        {
            count++;
        }
        if(i<m-1 && j>0 && board[i+1][j-1])
        {
            count++;
        }
        if(i>0 && j<n-1 && board[i-1][j+1])
        {
            count++;
        }
        if(i>0 && j>0 && board[i-1][j-1])
        {
            count++;
        }
       return count; 
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size(),count=0;
        vector<vector<int>>Board=board;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {    count=0;
                count=valid_cell(i,j,m,n,Board,count);
             cout<<count;
             
                if(board[i][j] && (count<2|| count>3))
                {
                    board[i][j]=0;
                }
                else if(!board[i][j] && count==3)
                {
                    board[i][j]=1;
                    
                }
                
            }
        }
    }
};