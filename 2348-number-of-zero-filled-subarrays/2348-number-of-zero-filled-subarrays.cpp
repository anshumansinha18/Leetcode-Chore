class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long total=0;
        long long int count=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                count++;
            else{
                total+= ((count+1)*count)/2;
                count=0;
            }
        }
        
        total+= ((count+1)*count)/2;
        return total;
    }
    
};