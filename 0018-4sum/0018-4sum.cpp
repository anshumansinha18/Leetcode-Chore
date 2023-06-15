class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        int n = nums.size();
        
        if(n<4){
            return res;
        }
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> s;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                
                int a = nums[i];
                int b = nums[j];
                int l=j+1;
                int r=n-1;
                while(l<r){
                    if((long long)a+b+nums[l]+nums[r]==target){
                        vector<int> vec = {a, b, nums[l], nums[r]};
                        s.insert(vec);
                        l++;
                        r--;
                    }else if((long long)a+b+nums[l]+nums[r]<target)
                        l++;
                    else
                        r--;
                }
            }
        }
        
        for(auto it: s)
            res.push_back(it);
        
        return res;
    }
};