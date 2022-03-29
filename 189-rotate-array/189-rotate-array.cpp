class Solution {
public:
    
    void reverse(vector<int> &arr, int low, int high)
    {
        int n = arr.size();
        int start=low;
        int end = high;
        
        while(start<end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
     
        int n= nums.size();
        k=k%n;
        reverse(nums, 0, (n-k)-1);
        reverse(nums, (n-k), n-1);
        reverse(nums, 0, n-1);
        
    }
};