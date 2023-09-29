class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res(arr.size(), -1);
        int max=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
            res[i]=max;
            if(arr[i]>max) max=arr[i];
        }
        
        return res;
    }
};