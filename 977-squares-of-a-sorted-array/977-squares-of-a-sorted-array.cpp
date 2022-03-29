class Solution {
public:
    
    
   
    
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        
    
        vector<int> leftArr;
        vector<int> rightArr;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
                leftArr.push_back(nums[i]*nums[i]);
            else
                rightArr.push_back(nums[i]*nums[i]);
        }
        
        
        int n1 = leftArr.size();
        int n2 = rightArr.size();
        
        int i=n1-1;
        int j=0;
        int k=0;
        
        while(i>=0 && j<n2)
            if(leftArr[i]<=rightArr[j])
                nums[k++] = leftArr[i--];
            else
                nums[k++] = rightArr[j++];
        
        while(i>=0)
            nums[k++] = leftArr[i--];
        while(j<n2)
            nums[k++] = rightArr[j++];
        
        return nums;
    
    }
};