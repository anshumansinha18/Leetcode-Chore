class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n+2, 1);
        vector<int> right(n+2, 1);
        
        for(int i=1;i<=n;i++){
            left[i]=left[i-1]*nums[i-1];
            right[n-i+1]=right[n-i+2]*nums[n-i];
        }
        
        vector<int> res(n);
        for(int i=1;i<=n;i++){
            res[i-1]=left[i-1]*right[i+1];
        }
        return res;
        
    }
};