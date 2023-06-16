class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int i=0;
        int j=0;
        int n= nums.size();
        if(k==0) return false;
        unordered_map<int, int> m; 
        while(j<n){
            if(abs(i-j)<=k){
                if(m.find(nums[j])!=m.end()){
                    return true;
                }
                else m[nums[j++]]++;
            }else{
                m.erase(nums[i]);
                i++;
            }
        }
        
        
        return false;
    }
};