class Solution {
public:
bool compare(string s, string l){
  string straight = s+l;
  string rev = l+s;
  if(rev>straight)
      return true;
  else
      return false;


}
int partition(vector<string>& arr, int low, int high){
    string pivot = arr[high];
    int i = low-1;

    for(int j=low;j<high;j++){
        if(compare(arr[j], pivot)){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;

}

void quickSort(vector<string>& arr, int low, int high){
    if(low>=high)
        return;

    int pivotIndex = partition(arr, low, high);
    quickSort(arr, low, pivotIndex-1);
    quickSort(arr, pivotIndex+1, high);
}
string largestNumber(vector<int>& nums) {
       vector<string> arr;
    for(int i=0;i<nums.size();i++){
        arr.push_back(to_string(nums[i]));
    }

    quickSort(arr, 0, arr.size()-1);
    string res = "";


   for(int i=arr.size()-1;i>=0;i--)
       res+=arr[i];
      int flag=0;
   for(int i=0;i<res.size();i++){
       if(res[i]!='0')
           flag=1;
   }
   if(flag==0) res="0";
return res;

}
};