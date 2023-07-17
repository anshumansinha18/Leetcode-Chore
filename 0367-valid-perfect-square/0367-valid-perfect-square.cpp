class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int low=1;
        int high=num;
        
        while(low<high){
            long long mid = low+(high-low)/2;
            
            if(num>mid*mid)
                low=mid+1;
            else
                high=mid;
        }
        
        return (long long)low*low==num;
    }
};