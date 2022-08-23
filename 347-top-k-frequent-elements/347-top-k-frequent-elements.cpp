class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
         unordered_map<int, int> m;
        
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        
        
        multimap<int, int> m1;
        for(auto it: m)
            m1.insert(pair<int, int>(it.second, it.first));
        
        
        vector<int> res;
        
        for(auto it = m1.rbegin();k>0;it++)
        {
            res.push_back(it->second);
            k--;
        }
        
        return res;
    }
};