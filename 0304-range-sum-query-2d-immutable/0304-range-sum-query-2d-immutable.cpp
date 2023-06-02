class NumMatrix {
    vector<vector<int>> arr;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        arr = matrix;
        for(int i=0;i<arr.size();i++){
            for(int j=1;j<arr[i].size();j++){
                arr[i][j] = arr[i][j-1]+arr[i][j];
            }
        }

        for(int j=0, k=j;j<arr[k].size();j++){
            for(int i=1;i<arr.size();i++){
                arr[i][j] = arr[i-1][j]+arr[i][j];
            }
        }

        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
             int a = row1==0?0:arr[row1-1][col2];
             int b = row1==0 || col1==0?0:arr[row1-1][col1-1];
             int c = arr[row2][col2];
             int d= col1==0?0:arr[row2][col1-1];

             int e = a-b;
             int f = c-d;
             return f-e;

    }
};