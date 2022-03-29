class Solution {
public:
    
    
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n);
        
        int low = 0; int high = n-1;
        
        for(int i=n-1;i>=0;i--)
        {
            if(abs(nums[low])<abs(nums[high]))
            {
                res[i] = nums[high]*nums[high];
                high--;
            }
            else
            {
                res[i] = nums[low]*nums[low];
                low++;
            }
        }
        
        return res;
    }
};