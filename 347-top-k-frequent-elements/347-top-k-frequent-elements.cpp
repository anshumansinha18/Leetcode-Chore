class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
         unordered_map<int, int> m;
        
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        
          vector<vector<int>> v(nums.size()+1);
        
          for(auto it: m){
              v[it.second].push_back(it.first);
          }
        
        vector<int> res;
        
        for(int i=v.size()-1;i>=0;i--)
        {
            if(!v[i].empty())
            for(int j=0;j<v[i].size();j++){
                if(k>0 ) res.push_back(v[i][j]);
                k--;  
            }
        }
              return res;
    }
};