class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        
        for(int i=0;i<nums.size();i++)
             m[nums[i]]++;
        
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]--;
               int c = target-nums[i];
               if(m[c]>0)
                   res.push_back(i);
            m[nums[i]]++;
        }
        
        return res;
    }
};