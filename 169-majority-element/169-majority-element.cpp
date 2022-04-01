class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int maj_el;
        
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
                maj_el = nums[i];
            if(maj_el == nums[i])
                count++;
            else
                count--;
        }
        
        return maj_el;
        
    }
};