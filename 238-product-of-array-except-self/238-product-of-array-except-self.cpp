class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> postfix(n);
        
       for(int i=0;i<n;i++)
        prefix[i] = i==0?nums[i]:prefix[i-1]*nums[i];

    for(int i=n-1;i>=0;i--)
        postfix[i] = i==n-1?nums[i]:postfix[i+1]*nums[i];
        
        vector<int> res(n);
        res[0] = postfix[1];
        res[n-1] = prefix[n-2];
        
        for(int i=1;i<n-1;i++)
        {
            res[i] = prefix[i-1]*postfix[i+1];
        }
        
        return res;
    }
};