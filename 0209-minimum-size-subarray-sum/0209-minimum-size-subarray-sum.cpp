class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i=0;
        int j=0;
        int n=nums.size();
        int min_l=INT_MAX;
        int sum=0;
        while(i<n){
            sum+=nums[i];
            if(sum>=target){
                min_l = min(min_l,i-j+1);
                sum -= (nums[j]+nums[i]);
                j++;
            }else{
                i++;
            }
        }
        
        return min_l == INT_MAX?0:min_l;
    }
};