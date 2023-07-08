class Solution {
public:
    
    int binarySearch(vector<int>& nums){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            if(nums[low]<nums[high]) return low;
            int mid = low+(high-low)/2;
            
            if(nums[low]<=nums[mid])
                low=mid+1;
            else
                high=mid;
            
        }
        return low;
    }
    
    int findMin(vector<int>& nums) {
       int start=0,end=nums.size()-1;
        
        while (start<end) {
            if (nums[start]<nums[end])
                return nums[start];
            
            int mid = (start+end)/2;
            
            if (nums[mid]>=nums[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        return nums[start];
    }
};