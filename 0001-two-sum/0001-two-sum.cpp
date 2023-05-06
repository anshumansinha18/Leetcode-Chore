class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        unordered_map<int, int> m;
        vector<int> res(2);
        
        for(int i=0;i<n;i++){
           m[nums[i]]++;
        }
        
        int x;
        int res1, res2, y;
        for(int i=0;i<n;i++){
            x = target-nums[i];
            m[nums[i]]--;
            
            if(m[x]){
                res1 = i;
                y = x;
            }
            m[nums[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(i!=res1 && nums[i]==y)
                res2 = i;
        }
        
        return {res1, res2};
    }
};