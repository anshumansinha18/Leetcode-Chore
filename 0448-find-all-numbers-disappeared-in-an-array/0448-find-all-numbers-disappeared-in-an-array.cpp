class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
          unordered_map<int, int> m;
        int n = nums.size();
        vector<int> res;
        
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        for(int i=1;i<=n;i++)
            if(!m[i])
                res.push_back(i);
        
        return res;
    }
};