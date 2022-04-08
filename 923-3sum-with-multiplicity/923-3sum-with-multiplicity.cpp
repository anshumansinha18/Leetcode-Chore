class Solution {
public:
    int calcSum(vector<int> v, unordered_map<int, int> m)
{
    int n=v.size();

    long long sum=0;
    if((v[0]==v[1])&& v[1]==v[2])
    {
        long long x = m[v[0]];
        sum = x*(x-1)/2*(x-2)/3;

    }
    else if(v[0]==v[1] || v[1]==v[2])
    {
        if(v[0]==v[1])
        {
            int x = m[v[0]];
            sum=(x*(x-1))/2;
            sum=sum*m[v[2]];
        }
        else
        {
            int x = m[v[1]];
            sum=(x*(x-1))/2;
            sum=sum*m[v[0]];
        }
    }
    else
    {
        sum=m[v[0]]*m[v[1]]*m[v[2]];
    }
    sum=sum%1000000007;
    return sum;

}

void merge(vector<int> &nums, int low, int mid, int high)
{
    int n1 = (mid-low+1);
    int n2 = (high-mid);

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for(int i=0;i<n1;i++)
        leftArr[i] = nums[low+i];
    for(int i=0;i<n2;i++)
        rightArr[i] = nums[mid+1+i];

    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
        if(leftArr[i]<= rightArr[j])
            nums[k++]=leftArr[i++];
        else
            nums[k++]=rightArr[j++];

    while(i<n1)
        nums[k++]=leftArr[i++];
    while(j<n2)
        nums[k++]=rightArr[j++];
}
void mergeSort(vector<int> &nums, int low, int high)
{
    if(low>=high)
         return;

    int mid = (low+high)/2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    merge(nums, low, mid, high);
}
int threeSumMulti(vector<int>& arr, int target) {
      mergeSort(arr, 0, arr.size()-1);
      int n = arr.size();
      int a=0;
      long long sum=0;
      unordered_map<int, int> m;

      for(int i=0;i<n;i++)
          m[arr[i]]++;

      vector<vector<int>> res;
      while(a<n-2)
      {
          int x = target-arr[a];
          int l = a+1;
          int h = n-1;
          while(l<h)
          {
              int b = arr[l];
              int c =arr[h];
              if(b+c<x)
                  l++;
              else if(b+c>x)
                  h--;
              else
              {
                  vector<int> v(3);
                  v[0]=arr[a],v[1]=arr[l],v[2]=arr[h];
                  res.push_back(v);
                  sum=sum+calcSum(v, m);
                  sum=sum%1000000007;
                  do{
                      l++;
                  }while(l<h && l<n-1 && arr[l]==arr[l-1]);
                  do{
                      h--;
                  }while(h>l && h>a && arr[h]==arr[h+1]);
              }
          }

          do{
              a++;
          }while(a<n-2 && arr[a]==arr[a-1]);
      }


      return (int)sum;
}
};