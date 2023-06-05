class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int i=0;
        int j=k-1;
        int res = INT_MAX;
        while(j<nums.size())
            res = min(res, nums[j++]-nums[i++]);
           
        return res;
    }
};