class Solution {
public: vector<vector<string>> sol; 
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n,string(n,'.'));
        solve(temp,0,n);
        return sol;
        
    }
    void solve(vector<string> &temp , int col , int queens)
    {
        if(col==temp.size() && queens==0)
            sol.push_back(temp);
        if(col>=temp.size())
            return ;
        
        for(int row= 0;row<temp.size();row++)
        {
            if(check(col,row,temp) == true)
            {
                temp[row][col]='Q';
                solve(temp,col+1,queens-1);
                temp[row][col] ='.';
 
            }
        }
        
        
    }
    bool check(int col,int row,vector<string> &board)
    {
        int duprow = row;
      int dupcol = col;
        int n = board.size();

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }
};