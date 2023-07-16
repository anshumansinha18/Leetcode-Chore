class Solution {
public:
    
    long long cummSum(int n){
        return (n % 2 == 0) ? (n / 2) * (long long)(n + 1) : (long long)n * ((n + 1) / 2);
    }
    int arrangeCoins(int n) {
        
        int low=1;
        int high=n;
        if(n==1) return 1; 
        while(low<high){
            int mid=low+(high-low)/2; 
            if(n>cummSum(mid)){
                low=mid+1;
            }else{
                high=mid;
            }
            
        }
        
        return n==cummSum(low)?low:low-1;
    }
};