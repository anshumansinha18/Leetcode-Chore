class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isRowUnique = true;
        bool isColUnique = true;
        bool isBoxUnique = true;


        map<char, int> m;
        for(int i=0;i<9;i++)
        {
            m.clear();
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.') m[board[i][j]]++;
                if(m[board[i][j]]>1){
                    return false;
                }
            }
        }


        m.clear();
        for(int j=0;j<9;j++)
        {
            m.clear();
            for(int i=0;i<9;i++)
            {
                if(board[i][j]!='.') m[board[i][j]]++;
                if(m[board[i][j]]>1)
                    return false;
            }

        }

        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                m.clear();
                for(int k=i;k<=i+2;k++)
                {
                    for(int l=j;l<=j+2;l++)
                    {
                        if(board[k][l]!='.') m[board[k][l]]++;
                        if(m[board[k][l]]>1)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};