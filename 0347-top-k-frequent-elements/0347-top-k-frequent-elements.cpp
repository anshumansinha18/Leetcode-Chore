class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        multimap<int, int> n;
        for(auto it: m)
            n.insert(pair<int, int>(it.second, it.first));
        
        vector<int> res;
        for(auto it = n.rbegin();it!=n.rend() && k>0;it++){
            res.push_back(it->second);
            k--;
        }
        
        return res;
    }
};