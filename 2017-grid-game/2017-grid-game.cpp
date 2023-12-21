class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        vector<vector<long long>> sum(n, vector<long long>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0) sum[i][j]=grid[i][j];
                else sum[i][j]=sum[i][j-1]+grid[i][j];
            }
        }
        long long minScore=LLONG_MAX;
        for(int i=0;i<m;i++){
            if(i==0)
                minScore = min(minScore, (sum[0][m-1]-sum[0][0]));
            else if(i==m-1){
                minScore = min(minScore, sum[1][i-1]);
            }else{
                minScore = min(minScore, max((sum[0][m-1]-sum[0][i]), (sum[1][i-1])));
            }
        }
        
        return minScore;
    }
};