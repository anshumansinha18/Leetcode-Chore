class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        int first=-1;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]--;
            if(m[target-nums[i]]!=0){
                first=i;
                break;
            }
            m[nums[i]]++;
        }
        int second=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target-nums[first])
                second=i;
        }
        
        return {first, second};
    }
};