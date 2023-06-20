class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long int sum=0;
        int j=0, max_f=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if((long long)nums[i]*(i-j+1) <= sum+k){
                max_f = max(max_f, i-j+1);
            }else{
                sum-= (nums[i]+nums[j]);
                j++;
                i--;
            }
        }
        
        return max_f;
    }
};