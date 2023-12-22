class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n=nums.size();
        int negCount=0;
        int zero = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                negCount++;
            }else if(nums[i]==0){
                zero++;
            }
        }
        
        if(zero) return 0;
        else if(negCount%2==0) return 1;
        else return -1;
        
     
    }
};