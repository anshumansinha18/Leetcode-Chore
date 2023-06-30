class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> d;
        int i=0, n=nums.size();
        int j=0;
        vector<int> res;
        while(j<n){
           
            while(!d.empty() && nums[j]>d.back()){
                d.pop_back();
            }
            
            d.push_back(nums[j]);
            
            if(j-i+1>=k){
                res.push_back(d.front());
                if(d.front()==nums[i]) d.pop_front();
                i++;
            }
            j++;
        }
        
        // while(!d.empty()){
        //    res.push_back(d.front());
        //     d.pop_front();
        // }
        return res;
    }
};