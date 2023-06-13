class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       
        int i=0;
        int n = nums.size();
        int j=0;
        long long res=0;
        
        while(i<n && j<n){
            if(nums[i]!=0){
                i++;
                j=i;
            }else{
                res+=i-j+1;
                i++;
            }
        }
        return res;
    }
    
};