class NumArray {
public:
    
    vector<int> cummSum;
    NumArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> cummSum(n+1);
        for(int i=0;i<n;i++){
            cummSum[i+1] = cummSum[i]+nums[i];
        }
        
        this->cummSum = cummSum;
    }
    
    int sumRange(int left, int right) {
        
         return cummSum[right+1]-cummSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */