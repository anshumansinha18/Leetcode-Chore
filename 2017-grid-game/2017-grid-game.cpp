class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
          int n = grid[0].size();
         
          vector<long long > pre1(n);
          vector<long long> pre2(n);
          for(int i=0;i<n;i++){
              if(i==0){
                  pre1[i]=grid[0][i];
                  pre2[i]=grid[1][i];
              }else{
                  pre1[i]=pre1[i-1]+grid[0][i];
                  pre2[i]=pre2[i-1]+grid[1][i];
              }
          }
        
      
          long long minSum=LLONG_MAX;
          for(int i=0;i<n;i++){
              long long sum = 0;
              if(i==0) sum = (pre1[n-1]-pre1[i]);
              else if(i==n-1) sum = pre2[i-1];
              else sum = max(pre2[i-1], pre1[n-1]-pre1[i]);
              
              minSum = min(minSum, sum);
              
          }
        
        return minSum;
    }
};