class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int low=0;
        int high=nums.size()-1;
        int n = nums.size();
        
        while(i<=high){
            if(nums[i]==2){
                swap(nums[i], nums[high]);
                high--;
            }else if(nums[i]==0){
                swap(nums[i], nums[low]);
                low++;
                i++;
            }else if(nums[i]==1){
                i++;
            }
        }
        
        
        
    }
};