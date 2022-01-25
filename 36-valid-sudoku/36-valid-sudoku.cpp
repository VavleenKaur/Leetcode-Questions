class Solution {
public:
    
    bool isValid(char c,int row, int col,vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c && i!=col)
            {
                return false;
            }
            if(board[i][col]==c && i!=row)
            {
                return false;
            }
            int ro=3*(row/3)+i/3;
            int co=3*(col/3)+i%3;
            if(board[ro][co]==c && ro!=row && co!=col)
            {
                return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.')
                {
                    if(!isValid(board[i][j],i,j,board))
                    { 
                        return false;
                    }
                    
                }
            }
        }
        return true;
     }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        return solve(board);
    }

        
        
};