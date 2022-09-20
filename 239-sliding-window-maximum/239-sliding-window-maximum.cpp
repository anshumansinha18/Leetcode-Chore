class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l=0,r=0;
        deque<int> d;
        vector<int> res;
        
        while(r<n)
        {
            while(!d.empty() && nums[r]>d.back())
                    d.pop_back();
            d.push_back(nums[r]);
            r++;
            
            if(r-l==k)
            {
                res.push_back(d.front());
                if(nums[l]==d.front())
                    d.pop_front();
                l++;
            }
        }
        
        return res;
    }
};