class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int max=arr[n-1];
        vector<int> res(n, -1);
        for(int i=n-2;i>=0;i--){
            res[i]=max;
            if(arr[i]>max){
                max=arr[i];
            }
            
        }
        return res;
    }
};