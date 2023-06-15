class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> s;
        for(int i=0;i<n-2;i++){
            int c = nums[i];
            
            int l = i+1;
            int r = n-1;
            while(l<r){
               if(nums[l]+nums[r]+c==0){
                   vector<int> vec = {c, nums[l], nums[r]};
                   s.insert(vec);
                   l++;
                   r--;
               }else if(nums[l]+nums[r]+c<0){
                   l++;
               }else
                   r--;
            }
            
        }
        
        vector<vector<int>> res;
        for(auto it: s)
            res.push_back(it);
        
        return res;
    }
};