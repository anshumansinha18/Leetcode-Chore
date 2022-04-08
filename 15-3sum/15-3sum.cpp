class Solution {
public:


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
vector<vector<int>> threeSum(vector<int>& nums) {
      mergeSort(nums, 0, nums.size()-1);
      int n = nums.size();
      int a=0;
      vector<vector<int>> res;
      while(a<n-2)
      {
          int x = -nums[a];
          int l = a+1;
          int h = n-1;
          while(l<h)
          {
              int b = nums[l];
              int c =nums[h];
              if(b+c<x)
                  l++;
              else if(b+c>x)
                  h--;
              else
              {
                  vector<int> v(3);
                  v[0]=nums[a],v[1]=nums[l],v[2]=nums[h];
                  res.push_back(v);

                  do{
                      l++;
                  }while(l<h && l<n-1 && nums[l]==nums[l-1]);
                  do{
                      h--;
                  }while(h>l && h>a && nums[h]==nums[h+1]);
              }
          }

          do{
              a++;
          }while(a<n-2 && nums[a]==nums[a-1]);
      }

     
      return res;
}

};