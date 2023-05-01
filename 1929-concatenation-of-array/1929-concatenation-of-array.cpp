class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;
        
        for(int i=0;i<2*n;i++)
            vec.push_back(nums[i%n]);
        
        return vec;
    }
};