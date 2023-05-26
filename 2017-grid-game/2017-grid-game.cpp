class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
         long long first = 0, second=0;
         long long minSum=LLONG_MAX;
        int n = grid[0].size();
        
         for(int i=0;i<n;i++){
             first+=grid[0][i];
         }
        
        
        for(int i=0;i<n;i++){
            first-=grid[0][i];
            minSum = min(minSum, max(first, second));
            second+=grid[1][i];
        }
        
        return minSum;
    }
};