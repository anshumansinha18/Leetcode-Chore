class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int n = arr.size();
        
        int count=0;
        int sum=0;
        int j=0;
        for(int i=0;i<n;i++){
            
            sum+=arr[i];
            if(i-j+1>k){
                sum-=arr[j];
                j++;
            }
            
            if(i-j+1==k){
                if(sum>=threshold*k)
                    count++;
            }
        }
        return count;
    }
};