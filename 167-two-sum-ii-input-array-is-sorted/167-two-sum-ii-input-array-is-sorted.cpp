class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        int l = 0;
        int r = n-1;
   
        while(l<r)
        {
            if(numbers[l]+numbers[r] == target) break;
            if(numbers[l]+numbers[r] > target) r--;
            else l++;
        }
        
        vector<int> res{l+1, r+1};
        
        return res;
        
    }
};