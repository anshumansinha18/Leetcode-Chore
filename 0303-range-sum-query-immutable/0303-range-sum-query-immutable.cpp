class NumArray {
public:
    
    //[-2, 0, 3, -5, 2, -1]
    vector<int> cumm;
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        cumm.resize(n+1);
        for(int i=0;i<n;i++){
            cumm[i+1]=cumm[i]+nums[i];
        }
        
        
        
    }
    
    int sumRange(int left, int right) {
        int n = cumm.size();

        return cumm[right+1]-cumm[left];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */