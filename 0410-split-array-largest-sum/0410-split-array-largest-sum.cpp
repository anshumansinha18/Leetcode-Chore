class Solution {
public:
    
    bool check(vector<int>& nums, int mid, int target){
        int n =nums.size();
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            if(sum>mid){
                sum=0;
                i--;
                count++;
            }
        }

        return count+1>target;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int low=0;
        int high=0;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            low = max(low, nums[i]);
            high+=nums[i];
        }
        
   
        while(low<high){
            int mid = (low+(high-low)/2);
            
            if(check(nums, mid, k))
                low=mid+1;
            else
                high=mid;
        }
        
        return low;
        
        
    }
};