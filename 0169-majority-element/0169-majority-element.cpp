class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int count=-2;
        int res = nums[0];
        
        for(int i=0;i<n;i++){
            if(nums[i]==res){
                count++;
            }
            else count--;
            
            if(count==-1){
                count=1;
                res=nums[i];
            }
        }
        
        return res;
    }
};