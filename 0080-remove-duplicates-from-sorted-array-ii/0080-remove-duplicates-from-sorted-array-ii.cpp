class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
               int i=0;
        
        int n = nums.size();
        
        int k=-1;
        int count=0;
        int res = nums[0];
        while(i<n){
 
            if(res==nums[i])
                count++;
            else count=1;
            res=nums[i];
            if(count<3){
                k++;
                swap(nums[i], nums[k]);
            }
            i++;
        }
        
        return k+1;
    }
};