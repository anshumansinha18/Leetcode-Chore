class Solution {
public:
    
    int partition(vector<int>& arr, int low, int high){
        int pivot = arr[high];
        int i=low-1;
        for(int j=low;j<high;j++)
        {
            if(arr[j]<pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        
        swap(arr[i+1], arr[high]);
        return i+1;
    }
    
    void quickSelect(vector<int>& arr, int low, int high,int n, int k){
        if(low>=high)
            return;
        
        int pivotIndex = partition(arr, low, high);
        if((n-k)>pivotIndex)
            quickSelect(arr, pivotIndex+1, high, n, k);
        else if((n-k)<pivotIndex)
            quickSelect(arr, low, pivotIndex-1, n, k);
        else
            return;
        
    }
        
    
    int findKthLargest(vector<int>& nums, int k) {
        
       quickSelect(nums, 0, nums.size()-1, nums.size(), k); 
        
        return nums[nums.size()-k];
    }
};