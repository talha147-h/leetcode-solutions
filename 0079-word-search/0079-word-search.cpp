class Solution {
public:

    bool dfs(int i,int j,vector<vector<char>> &board,string word,int idx)
    {
        if(idx==word.size())return true;
     int n=board.size();
        int m=board[0].size();
        char ch=board[i][j];
       board[i][j]='0';
       bool right=false,left=false,up=false,down=false;    
       if(j+1<m && board[i][j+1]==word[idx])
        right=dfs(i,j+1,board,word,idx+1);
        if(j-1>=0 && board[i][j-1]==word[idx])
        left=dfs(i,j-1,board,word,idx+1);
        if(i+1<n && board[i+1][j]==word[idx])
        down=dfs(i+1,j,board,word,idx+1);
        if(i-1>=0 && board[i-1][j]==word[idx])
        up=dfs(i-1,j,board,word,idx+1);
      board[i][j]=ch;
return right||left||down||up;
       return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            bool found=false;
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                 found=dfs(i,j,board,word,1);
                if(found == true)return true;
            }
        }
        return false;
    }
};