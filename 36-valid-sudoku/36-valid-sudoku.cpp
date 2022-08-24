class Solution {
public:
    
    bool checkRow(vector<vector<char>>& board){
         
        for(int i=0;i<9;i++)
        {
            unordered_set<int> s;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                if(!s.insert(board[i][j]).second)
                    return false;
            }
        }
        return true;
    }
    
    bool checkCol(vector<vector<char>>& board){
         
        for(int i=0;i<9;i++)
        {
            unordered_set<int> s;
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.')
                if(!s.insert(board[j][i]).second)
                    return false;
            }
        }
        return true;
    }
    
    bool checkBox(vector<vector<char>>& board){
     
        
        vector<unordered_set<char>> box(9);
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int boxNo = i/3*3 + j/3;
                
                if(board[i][j]!='.') {
                    auto it = box[boxNo].insert(board[i][j]);
                    if(!it.second)
                        return false;
                    
                    }
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool x = checkRow(board);
        bool y = checkCol(board);
        bool z = checkBox(board);
        
        cout<<x<<endl;
        cout<<y<<endl;
        cout<<z<<endl;
        
        if(x==true && y == true && z == true)
            return true;
        else 
            return false;
    }
};