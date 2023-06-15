
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1000000007;
        sort(nums.begin(), nums.end());
        int low=0;
        int high = nums.size()-1;
        int sum=0;
        
        vector<int> pow1(nums.size(), 1);
        
        for(int i=1;i<nums.size();i++){
            pow1[i]=(pow1[i-1]*2)%mod;
        }
        
        while(low<=high){
            if(nums[low]+nums[high]>target){
                high--;
            }else{
                 sum = (sum+ pow1[high-low])%mod;
                low++;
            }
        }
        
        return sum;
        // return 0;
    }
};