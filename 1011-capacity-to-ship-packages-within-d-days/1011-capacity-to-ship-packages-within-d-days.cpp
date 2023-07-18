class Solution {
public:
    
    bool condition(vector<int>& nums, int mid, int days){
        int sum=0;
        int count=1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>mid){
                sum=0;
                count++;
                i--;
            }
        }
        if(count>days) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        
        int low=0;
        int high=0;
        for(int i=0;i<n;i++){
            low=max(low, weights[i]);
            high+=weights[i];
        }
        
        while(low<high){
            int mid = low+(high-low)/2;
            
            if(condition(weights, mid, days))
                low=mid+1;
            else
                high=mid;
        }
        
        return low;
    }
};