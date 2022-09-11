class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        
        
        unordered_map<int, int> m;
        
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        int i=0, max_len=0;
        while(i<n)
        {
            if(!m[nums[i]-1])
            {
                int len=1;
                while(m[nums[i]+len])
                    len++;
                
                max_len = max(max_len, len);
            }
            
            i++;
        }
        
        return max_len;
    }
};