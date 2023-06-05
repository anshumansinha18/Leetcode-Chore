class Solution {
public:
   int firstMissingPositive(vector<int>& nums) {

     int n = nums.size();

     for(int i=0;i<n;i++){
         if(nums[i]<0)
             nums[i]=0;
     }

     for(int i=0;i<n;i++){
         if(nums[i]!=0 && abs(nums[i])-1<n){
             if(nums[abs(nums[i])-1]==0)
                 nums[abs(nums[i])-1]=-1*abs(nums[i]);
             else
                 nums[abs(nums[i])-1]=-1*abs(nums[abs(nums[i])-1]);
         }
     }

     int i=0;
     while(i<n && nums[i]<0){
         i++;
     }

     return i+1;

 }
};