class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(auto x:nums)
            m[x]++;
        
        for(auto x:nums)
            if(m[x]>1)
                return true;
        
        return false;
    }
};