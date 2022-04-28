class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> m1;
        for(int i=0;i<nums.size();i++)
        {
            m1[nums[i]]++;
        }
        
        multimap<int, int> m2;
        
        for(auto it = m1.begin();it!=m1.end();it++)
               m2.insert(pair<int, int>(it->second, it->first));
        
        vector<int> res;
        for(auto it = m2.rbegin();k>0;it++,k--)
             res.push_back(it->second);
        
        return res;
            
            
    }
};