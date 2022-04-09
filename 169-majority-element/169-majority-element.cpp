class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int maj_el = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            
            if(maj_el == nums[i])
                count++;
            else
                count--;
            
            if(count==0){
                maj_el = nums[i];
                count=1;
            }
        }
        
        return maj_el;
        
    }
};