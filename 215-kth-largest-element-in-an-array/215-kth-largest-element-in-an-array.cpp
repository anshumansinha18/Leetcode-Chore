class Solution {
public:
    
    void max_heapify(vector<int>&nums, int n, int i)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        int largest;
        
        if(left<n && nums[left]>nums[i])
            largest = left;
        else
            largest = i;
        
        if(right<n && nums[right]>nums[largest])
            largest = right;
        
        if(largest!=i)
        {
            swap(nums[i], nums[largest]);
            
            max_heapify(nums, n, largest);
        }
    }
    
    int build_heap(vector<int>& nums, int n, int k)
    {
        for(int i=n/2-1;i>=0;i--)
            max_heapify(nums, n, i);
        
        int i=n;
        int t = k;
        while(k>0 && i>0)
        {
            swap(nums[0], nums[i-1]);
            i--;
            max_heapify(nums, i, 0);
            k--;
        }
        
        return nums[n-t];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        return build_heap(nums, nums.size(), k);
    }
};