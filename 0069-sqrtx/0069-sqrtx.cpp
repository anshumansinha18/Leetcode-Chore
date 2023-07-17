class Solution {
public:
    int mySqrt(int x) {
        
        int low=0;
        int high=x;
        
        while(low<high){
            long long mid = low+(high-low)/2;
            
            if(x>mid*mid)
                low=mid+1;
            else
                high=mid;
        }
        
        return (long long)low*low==x?low:low-1;
    }
};