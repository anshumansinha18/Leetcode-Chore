class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
          int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        
        
        for(int i=0;i<n;i++)
        {
            if(i==0) left[i] = nums[i];
            else left[i] = left[i-1]*nums[i];
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1) right[i] = nums[i];
            else  right[i] = right[i+1]*nums[i];
        }
        
        
      
        
        vector<int> res(n);
        res[0] = right[1];
        res[n-1] = left[n-2];
        
            
        for(int i=1;i<n-1;i++)
        {
            res[i] = left[i-1]*right[i+1];
        }
        
        return res;
    }
};