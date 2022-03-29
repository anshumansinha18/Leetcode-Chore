class Solution {
public:
    
    
    void merge(vector<int>& arr, int low, int mid, int high)
    {
        int n1 = (mid-low+1);
        int n2 = (high-(mid+1)+1);
        
        vector<int> leftArr(n1);
        vector<int> rightArr(n2);
        
        for(int i=0;i<n1;i++)
            leftArr[i] = arr[i+low];
        for(int i=0;i<n2;i++)
            rightArr[i] = arr[mid+1+i];
        
        int i=0;
        int j=0;
        int k=low;
        
        while(i<n1 && j<n2)
        {
            if(leftArr[i]<=rightArr[j])
                arr[k++] = leftArr[i++];
            else
                arr[k++] = rightArr[j++];
        }
        
        while(i<n1)
            arr[k++] = leftArr[i++];
        while(j<n2)
            arr[k++] = rightArr[j++];
    }
    void mergeSort(vector<int>& arr, int low, int high)
    {
        if(low>=high)
            return;
        
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
    
    vector<int> sortedSquares(vector<int>& nums) {
        
        
 
        
        for(int i=0;i<nums.size();i++)
            nums[i] = nums[i]*nums[i];
        
        mergeSort(nums, 0, nums.size()-1);
        
        return nums;
        
    }
};