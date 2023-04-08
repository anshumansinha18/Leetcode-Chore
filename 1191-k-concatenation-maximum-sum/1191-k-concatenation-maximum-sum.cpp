class Solution {
public:
    
    long long int kadane(vector<int> &arr, int n){

    long long int sum=arr[0];
    long long int maxim=arr[0];

    for(int i=1;i<n;i++){
        if(sum+arr[i]>arr[i]){
            sum+=arr[i];
        }else
            sum=arr[i];
        maxim = max(maxim, sum);
    }

    return maxim<0?0:maxim;
}
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
         if(k==1)
        return kadane(arr, n);

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    vector<int> newArr(n*2);
    for(int i=0;i<n*2;i++){
        newArr[i]=arr[i%n];
    }
    if(sum<0){
        return kadane(newArr, n*2)%1000000007;
    }else{
        return kadane(newArr, n*2)%1000000007 + (long long)(k-2)*(long long)sum%1000000007;
    }
    }
};