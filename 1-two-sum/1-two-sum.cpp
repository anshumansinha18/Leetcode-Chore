class Solution {
public:
    
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m, index;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
          m[nums[i]]++;  
          index[nums[i]] = i;
        }
        
        
        int ans1;
        int ans2;
         for(int i=0;i<n;i++)
         {
             int a = nums[i];
             int b = target - a;
             m[a]--;
             
             if(m[b])
             {
                 ans1 = i;
                 ans2 = index[b];
                 break;
             }
             else
                 m[a]++;
                 
         }
        
        vector<int> v{ans1, ans2};
        
        
        return v;
    }
};