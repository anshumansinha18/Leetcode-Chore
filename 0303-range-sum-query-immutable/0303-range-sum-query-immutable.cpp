class NumArray {
public:
    
    //[-2, 0, 3, -5, 2, -1]
    vector<int> cumm;
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        cumm.resize(n);
        for(int i=0;i<n;i++){
            if(i==0) cumm[i]=nums[i];
            else cumm[i]=cumm[i-1]+nums[i];
        }
    
        
    }
    
    int sumRange(int left, int right) {
        int n = cumm.size();
       
        if(left==0 && right==n-1) return cumm[right];
        if(left==0) return cumm[right];
        if(right==n-1)  return cumm[n-1]-cumm[left-1];
        else return cumm[right]-cumm[left-1];
        
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */