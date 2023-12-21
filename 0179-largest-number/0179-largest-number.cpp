class Solution {
public:
    bool compare(int x, int y){
        string s1=to_string(x);
        string s2=to_string(y);
        string comb1 = s1+s2;
        string comb2=s2+s1;
        return comb1>comb2;
    }
    int partition(vector<int>& nums, int low, int high){
        int i=low-1;
        int pivot=nums[high];
        for(int j=low;j<high;j++){
            if(compare(nums[j], pivot)){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        
        swap(nums[i+1], nums[high]);
        return i+1;
    }
    
    void quickSort(vector<int> &nums, int low, int high){
        
        if(low>=high) return;
        
        int pivotIndex = partition(nums, low, high);
        quickSort(nums, low, pivotIndex-1);
        quickSort(nums, pivotIndex+1, high);
    }
    
    string largestNumber(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        string res="";
        for(auto it: nums){
            res+=to_string(it);
        }
        if(res[0]=='0') return "0";
        return res;
    }
    
};