class Solution {
public:
    
    int binarySearch(vector<int>& arr, int l, int r, int data){
        if(l>r)
            return -1;
        
        int mid = l + (r-l)/2;
        
        if(arr[mid] == data)
            return mid;
        else if(arr[mid]<data)
            return binarySearch(arr, mid+1, r, data);
        else
            return binarySearch(arr, l, mid-1, data);
    }
    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int index = binarySearch(nums, 0, n-1, target);
        
        return index;
    }
};