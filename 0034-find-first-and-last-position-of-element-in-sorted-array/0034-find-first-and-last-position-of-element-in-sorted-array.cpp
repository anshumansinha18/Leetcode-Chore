class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int n =nums.size();

        vector<int> res = {-1, -1};

        if(nums.size()==1 && nums[0]==target){
            res = {0,0};
            return res;
        }

        int minIndex = n;
        int maxIndex=-1;
        while(low<=high){
            
            int mid = low+(high-low)/2;

            if(nums[mid]==target){
                minIndex = min(minIndex, mid);
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout<<minIndex;

        if(minIndex>=n) return {-1, -1};

        low=0;
        high=n-1;
        while(low<=high){
            
            int mid = low+(high-low)/2;

            if(nums[mid]==target){
                maxIndex = max(maxIndex, mid);
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout<<" "<<maxIndex;
        return {minIndex, maxIndex};
    }
};