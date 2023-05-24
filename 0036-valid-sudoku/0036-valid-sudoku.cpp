class Solution {
public:
 
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_map<char, int>> row(9);
        vector<unordered_map<char, int>> column(9);
        vector<unordered_map<char, int>> box(9);
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]!='.'){
                    int boxId = i/3*3 + j/3;
                    if(row[i][board[i][j]] || column[j][board[i][j]] || box[boxId][board[i][j]])                              return false;
                    else{
                        row[i][board[i][j]]++;
                        column[j][board[i][j]]++;
                        box[boxId][board[i][j]]++;
                    }
                }
            }
        }
        
        
        return true;
        
        
    }
};