class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n);
        
        vector<int> l(n);
         vector<int> r(n);
        l[0] = nums[0];
         r[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            l[i]=l[i-1]*nums[i];
        }
        
        for(int i=n-2;i>=0;i--){
            r[i]=r[i+1]*nums[i];
        }
        
        for(int i=0;i<n;i++){
            if(i==0) res[i] = r[i+1];
            else if(i==n-1) res[i]=l[i-1];
            else res[i]=l[i-1]*r[i+1];
        }
        
        return res;
        
    }
};