class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // [3,2,2,3]
        // [2,2,3,3]
        
        //count=2;
        
        int n = nums.size();
        
        int i=-1;
        int j=0;
        
        while(j<n){
            if(nums[j]!=val){
                //swap
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
        
        return i+1;
        
    }
};