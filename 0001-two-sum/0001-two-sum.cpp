class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //store the array elements in the map:
        
        int n = nums.size();
        
        unordered_map<int, int> m;
        
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        //arr:  2 7 11 15
        // map: 
        //2->0
        //7->1
        //11->1
        //15->1
        
        int x=-1;
        for(int i=0;i<n;i++){
            m[nums[i]]--;
            if(m[target-nums[i]]!=0){
                x=i;
            }
            m[nums[i]]++;
        }
        int y=-1;
        for(int i=0;i<n;i++){
            if(target-nums[x]==nums[i] && x!=i) y=i;
        }
        
        return {x,y};
        
    }
};