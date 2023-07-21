class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0;
        int high=n-1;
        vector<int> res(2, -1);
        if(n==0) return res;
        while(low<high){
            int mid=low+(high-low)/2;
            
            if(target>nums[mid])
                low=mid+1;
            else
                high=mid;
        }
        
        if(nums[low]!=target) return res;
        else res[0]=low;
        
        low=0;
        high=n-1;
        
        while(low<=high){
            int mid=ceil(low+(high-(double)low)/2);
            
            if(target>=nums[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        
        res[1]=high;
        return res;
        
    }
};