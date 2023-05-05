class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int n = arr.size();
        
        int max = arr[n-1];
        vector<int> ans(n);
        
        ans[n-1] = -1;
        for(int i=n-2;i>=0;i--){
            ans[i]=max;
            if(arr[i]>max)
                max=arr[i];
        }
        
        return ans;
    }
};