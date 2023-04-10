class Solution {
public:
    
    int findPivot(vector<int>& nums){
        
        int low=0;
        int high = nums.size()-1;
        int res=low;

        if(nums[low]<=nums[high])
           return res;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]>nums[mid+1])
             {
                 res=mid+1;
                 break;
             }
            else if(nums[mid-1]>nums[mid])
             { 
                 res=mid;
                 break;
             }
            else if(nums[low]<=nums[mid])
               low=mid+1;
            else
               high=mid-1;
        }

        return res;

    }

    int search(vector<int>& nums, int target) {
        
        int pivot = findPivot(nums);
        int low=pivot;
        int n=nums.size();
        int high=pivot+(n-1);
        int res=-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid%n]==target)
              { 
                 res=mid%n;
                 break;
              }
            else if(target > nums[mid%n]){
                low=mid+1;
            }
            else
               high=mid-1;
        }
        return res;

    }
};