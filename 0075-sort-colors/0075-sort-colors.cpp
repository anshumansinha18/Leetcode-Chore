class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int low=0;
        int high = n-1;
        int i=0;
        
        while(i<n && i<=high){
            
            if(nums[i]==0){
                swap(nums[i], nums[low]);
                i++;
                low++;
            }
            else if(nums[i]==1){
                i++;
            }else{
                swap(nums[i], nums[high]);
                high--;
            }
        }
        
        
    }
};