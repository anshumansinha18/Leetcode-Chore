class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<int> p(matrix.size(), -1);
        vector<int> q(matrix[0].size(), -1);
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    p[i] = 0;
                    q[j] = 0;
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(p[i]==0 || q[j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};