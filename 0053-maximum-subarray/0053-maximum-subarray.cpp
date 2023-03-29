class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
    int maxim = sum;
    for(int i=1;i<nums.size();i++){
        if(nums[i]<sum+nums[i]){
            sum += nums[i];
        }else{
            sum=nums[i];
        }
        maxim = max(sum, maxim);
    }
    return maxim;
    }
};