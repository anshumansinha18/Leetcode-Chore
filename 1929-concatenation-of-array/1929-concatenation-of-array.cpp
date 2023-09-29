class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(2*nums.size());
        
        for(int i=0;i<2*nums.size();i++){
             res[i]=nums[i%nums.size()];
        }
        
        return res;
    }
};