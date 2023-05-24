class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> m;
        int maxL=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        
        for(int i=0;i<n;i++){
            int length=1;
            
            if(!m[nums[i]-1]){
                int x = nums[i];
                while(m[++x])
                    length++;
            }
            
            maxL = max(maxL, length);
        }
        
        return maxL;
    }
};