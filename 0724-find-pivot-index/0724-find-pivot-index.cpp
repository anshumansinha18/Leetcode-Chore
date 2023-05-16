class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        
        
        vector<int> leftArr(n);
        vector<int> rightArr(n);
        
        for(int i=0;i<n;i++)
            leftArr[i] = i==0? nums[i] : leftArr[i-1]+nums[i];
        
        for(int i=n-1;i>=0;i--)
            rightArr[i] = i== n-1 ? nums[i] : rightArr[i+1] + nums[i];
        
        for(int i=0;i<n;i++){
            if(leftArr[i]==rightArr[i])
                return i;
        }
        return -1;
    }
};