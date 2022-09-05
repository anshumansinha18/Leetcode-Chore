class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0;i<n;i++)
           m[nums[i]]++;
        
        
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            if(m[nums[i]-1]==0)
            {
                int a = nums[i]+1, len = 1 ;
                while(m[a]>0)
                {
                    len++;
                    a++;
                }
                
                maxLen = max(maxLen, len);
            }
        }
        
        return maxLen;
     
    }
};