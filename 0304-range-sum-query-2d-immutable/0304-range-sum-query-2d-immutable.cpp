class NumMatrix {
public:
    
    vector<vector<int>> arr;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        arr = vector<vector<int>>(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0) arr[i][j]=matrix[i][j];
                else arr[i][j]=arr[i][j-1]+matrix[i][j];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0) arr[j][i]=arr[j][i];
                else arr[j][i]=arr[j-1][i]+arr[j][i];
            }
        }
        
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a=0,b=0;
        if(row1!=0)
            a = arr[row2][col2]-arr[row1-1][col2];
        else a = arr[row2][col2];
        
        if(col1!=0 && row1!=0){
            b=arr[row2][col1-1]-arr[row1-1][col1-1];
        }else if(col1!=0){
            b=arr[row2][col1-1];
        }
        
        
        return a-b;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */