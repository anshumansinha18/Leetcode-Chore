class Solution {
public:
    
    void max_heapify(vector<int>& nums, int n, int i)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        int largest;
        if(left<n && nums[left]>nums[i])
            largest = left;
        else
            largest =i;
        
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
        for(int i = n/2-1;i>=0;i--)
            max_heapify(nums, n, i);
        
        int size = k;
        int i=n;
        int res=0;
        while(k>(size/2))
        {
            int maxim = nums[0];
            swap(nums[i-1], nums[0]);
            i--;
            max_heapify(nums, i, 0);
            res++;
            k = k-maxim;
        }
        return res;
    }
    
    int minSetSize(vector<int>& arr) {
        
        map<int, int> m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        
        vector<int> nums;
        for(auto it=m.begin();it!=m.end();it++)
            nums.push_back(it->second);
        
        
        return build_heap(nums, nums.size(), arr.size());
        
    }
}; 