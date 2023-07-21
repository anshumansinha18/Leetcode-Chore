class Solution {
public:
    
    int findPivot(vector<int>&nums){
        int low=0;
        int high=nums.size()-1;
        
        while(low<high){
            int mid = low+(high-low)/2;
            
            if(nums[low]<=nums[mid] && nums[low]>nums[high])
                low=mid+1;
            else
                high=mid;
        }
        
        return low;
    }
    
    int search(vector<int>& nums, int target) {
        
        int pivot = findPivot(nums);
        // cout<<pivot;
        int n = nums.size();
        int low=pivot;
        int high = low+(n-1);
        
        while(low<high){
            int mid = low+(high-low)/2;
            
            if(target>nums[mid%n]){
                low=mid+1;
            }else
                high=mid;
        }
        
        return nums[low%n]==target?low%n:-1;
    }
};