class Solution {
public:
    
    int binarySearch(vector<int>& nums){
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            cout<<"s";
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
        
        int mid = binarySearch(nums);
        return nums[mid];
    }
};