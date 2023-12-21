class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        vector<vector<int>> count(nums.size()+1);
        
        for(auto it: m){
            count[it.second].push_back(it.first);
        }
        
        vector<int> res;
        
        for(int i=nums.size();i>=0&& k!=0;i--){
                for(int j=0;j<count[i].size();j++){
                    res.push_back(count[i][j]);
                    k--;
                }
     
          
        }
        return res;
    }
         
    
};