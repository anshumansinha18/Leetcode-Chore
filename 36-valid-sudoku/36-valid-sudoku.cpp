class Solution {
public:
     bool isValidSudoku(vector<vector<char>>& board) {

        set<string> s;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.') {
                    int boxno = i / 3 * 3 + j / 3;
                    string row = "r", col = "c", box = "b";

                    row += char(i + '0');
                    row += char(board[i][j]);

                    col += char(j + '0');
                    col += char(board[i][j]);

                    box += char(boxno + '0');
                    box += char(board[i][j]);

                    if (s.empty() || (s.find(row) == s.end() && s.find(col) == s.end() && s.find(box) == s.end())) {
                        s.insert(row);
                        s.insert(col);
                        s.insert(box);
                    } else
                        return false;
                }
            }

        }
           return true;
    }
};