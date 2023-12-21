class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n=nums.size();
        m[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            int val = sum-k;
            if(m[val]){
                count+=m[val];
            }
            m[sum]++;
        }
        
        return count;
    }
};