class Solution {
public:
    
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n);
        int i=0;
        int j=nums.size()-1;
        int k=nums.size()-1;
        //merge sort application:
        while(i<=j){
            if(abs(nums[j])>=abs(nums[i])){
                res[k--]=nums[j]*nums[j];
                j--;
            }else{
                res[k--]=nums[i]*nums[i];
                i++;
            }
        }
        
        return res;
    }
};