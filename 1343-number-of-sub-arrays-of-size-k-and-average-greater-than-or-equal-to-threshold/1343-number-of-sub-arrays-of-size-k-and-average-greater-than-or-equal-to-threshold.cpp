class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int n = arr.size();
        int sum=0;
        int count=0;
        double avg=0;
        int j=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            avg=(double)sum/(i-j+1);

            
            if(i-j+1==k){
                if(avg>=threshold){
                count++;
            }
                sum-=arr[j];
                j++;
            }
            
        }
        
        return count;
    }
};