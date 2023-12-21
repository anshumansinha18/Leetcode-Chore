class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        int maxCount=0;
        
        for(int i=0;i<n;i++){
            
            //check if a number is the start of the sequence.
            if(m[nums[i]-1]==0){
                //not existing:
                int num = nums[i];
                int count=0;
                while(m[num]){
                    num++;
                    count++;
                }
                maxCount=max(maxCount, count);
            }
        }
        
        return maxCount;
    }
};