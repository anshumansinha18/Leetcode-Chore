class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        long long sum=0;
        int n=nums.size();
        int j=0;
        int count=0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            
            sum+=nums[i];
            
            if((long long)(i-j+1)*nums[i]-sum>k){
                sum-=(nums[j]+nums[i]);
                j++;
                i--;
            }else count=max(count, i-j+1);
        }
        
        return count;
    }
};