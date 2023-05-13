class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        
        int i=-1;
        for(int j=0;j<n;j++){
            if(nums[j]!=val){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        
        for(int i=0;i<n;i++)
            cout<<nums[i]<<" ";
        
        return i+1;
    }
};