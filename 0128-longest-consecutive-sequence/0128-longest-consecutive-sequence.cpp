class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> m;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        
        int maxL = 0;
        for(int i=0;i<n;i++){
            int length=1;
            
            if(m[nums[i]]){
                m[nums[i]]--;
                int x = nums[i];
                while(m[--x]){
                    length++;
                    m[x]--;
                }
                
                x=nums[i];
                while(m[++x]){
                    length++;
                    m[x]--;
                }
                
                maxL = max(maxL, length);
            }
        }
        
        return maxL;
    }
};