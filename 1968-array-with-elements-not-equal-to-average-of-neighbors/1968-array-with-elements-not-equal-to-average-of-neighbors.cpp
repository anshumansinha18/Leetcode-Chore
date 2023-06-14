class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> res;
        int i=0,j=n-1;
        while(i<j){
            res.push_back(nums[i]);
            res.push_back(nums[j]);
            i++;
            j--;
        }
       if(i==j) res.push_back(nums[i]);
        
        return res;
    }
};