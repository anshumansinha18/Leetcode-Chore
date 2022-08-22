class Solution {
public:
    
    int binarySearch(vector<int>& arr, int low, int high, int b, int i)
    {
        int ans=-1;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
           
            if(arr[mid]==b && mid!=i)
            {
                ans = mid;
                break;
            }
            else if(b>arr[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        
        return ans;
        
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
    
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> res;
        int ans1, ans2;
        
        for(int i=0;i<n;i++)
        {
           int b = target - nums[i];
            
            int x = binarySearch(nums, 0, n-1, b, i);
            if(x!=-1)
            {
                ans1 = i;
                ans2=x;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[ans1]==temp[i] || nums[ans2] == temp[i])
                res.push_back(i);
        }
        
        return res;
    }
};