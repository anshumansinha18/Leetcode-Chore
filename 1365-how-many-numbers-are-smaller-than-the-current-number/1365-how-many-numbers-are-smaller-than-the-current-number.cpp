class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> count(101, 0);
        
        for(int i=0;i<nums.size();i++)
            count[nums[i]]++;
        
        vector<int> count2(101, 0);
        for(int i=1;i<101;i++)
        {
            count2[i] = count2[i-1]+count[i-1];
        }
        
        vector<int> res;
        for(int i=0;i<nums.size();i++)
             res.push_back(count2[nums[i]]);
        
        return res;
    }
};