class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            int val = abs(nums[i]);
            nums[val-1]=-1*(abs(nums[val-1]));
        }
        
        vector<int> res;
        for(int i=0;i<n;i++){
            if(nums[i]>0) res.push_back(i+1); 
        }
        return res;
    }
};