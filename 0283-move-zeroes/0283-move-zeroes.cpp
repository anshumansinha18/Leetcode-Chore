class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int k=-1;
        int n= nums.size();
        
        int i=0;
        
        while(i<n){
            if(nums[i]!=0){
                k++;
                swap(nums[i], nums[k]);
            }
            i++;
        }
        
        
    }
};