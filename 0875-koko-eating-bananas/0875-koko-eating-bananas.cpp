class Solution {
public:
    bool condition(vector<int> &nums, int mid, int h){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid==0) count+=nums[i]/mid;
            else count+= nums[i]/mid +1;
        }
        return count>h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxVal=0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            maxVal = max(maxVal, piles[i]);
        }
        
        int low=1;
        int high=maxVal;
        
        while(low<high){
            int mid = (low+(high-low)/2);
            
            if(condition(piles, mid, h)){
                low=mid+1;
            }else
                high=mid;
        }
        return low;
    }
};