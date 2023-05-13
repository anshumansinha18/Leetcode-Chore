class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        
        int i=-1;
        for(int j=0;j<n;j++){
            if(nums[j]!=val){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        
        
        return i+1;
    }
};