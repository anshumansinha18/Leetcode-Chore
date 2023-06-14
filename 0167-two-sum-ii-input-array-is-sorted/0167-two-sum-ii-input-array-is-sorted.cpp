class Solution {
public:
    
    int binarySearch(vector<int> &nums,int x, int i){
        
        int low=0;
        int high=nums.size()-1;
        int n = nums.size();
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(nums[mid]==x && mid!=i){
                return mid;
            }else if(mid==i && mid<n-1 && nums[mid+1]==x)
                return mid+1;
            else if(x>nums[mid]) low=mid+1;
            else high=mid-1;
        }
        
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        
        vector<int> res(2);
        for(int i=0;i<n;i++){
            int x = target-numbers[i];
            
            int index = binarySearch(numbers,x, i);
            if(index!=-1){
                res = {i+1, index+1};
                break;
            }
        }
        
        return res;
    }
};