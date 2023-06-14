class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int low=0;
        int high = numbers.size()-1;
        
        while(low<high){
            if(numbers[low]+numbers[high]==target) break;
            else if(numbers[low]+numbers[high]>target) high--;
            else low++;
        }
        
        vector<int> res = {low+1, high+1};
        return res;
    }
};