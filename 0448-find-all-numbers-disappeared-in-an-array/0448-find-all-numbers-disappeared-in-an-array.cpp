class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
          
        vector<int> res;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            int idx = abs(nums[i])-1;
            nums[idx] = -1*abs(nums[idx]);
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                res.push_back(i+1);
            }
        }
        
        return res;
        
    }
};