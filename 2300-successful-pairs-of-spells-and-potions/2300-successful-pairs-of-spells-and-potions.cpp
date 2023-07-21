class Solution {
public:
    
    int binarySearch(vector<int>& nums, int spell, long long sucess){
        
        int n = nums.size();
        int low=0;
        int high=n-1;
        
        while(low<high){
            int mid = low + (high-low)/2;
            
            if(spell*(long long)nums[mid]<sucess)
                low=mid+1;
            else
                high=mid;
        }
        
        return nums[low]*(long long)spell<sucess?0:n-low;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        
        sort(potions.begin(), potions.end());
        vector<int> res;
        int n1=spells.size();
        int n2=potions.size();
        for(int i=0;i<n1;i++){
            
            res.push_back(binarySearch(potions, spells[i], success));
        }
        
        return res;
    }
};