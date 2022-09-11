class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>& arr = nums;
        int l=0;
        int r=0;
        
        deque<int> d;
        vector<int> res;
        
        while(r<n)
        {
            if(r-l==k)
            {
                res.push_back(d.front());
                if(d.front()==arr[l])
                    d.pop_front();
                l++;
            }
            else
            {
                while(!d.empty() && arr[r]>d.back())
                {
                    d.pop_back();
                }
                d.push_back(arr[r]);
                r++;
            }
        }
        
        
        res.push_back(d.front());
        return res;
    }
};