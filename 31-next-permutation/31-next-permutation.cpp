class Solution {
public:
   void reverse(vector<int>& nums, int i, int j)
{
    while(i<j)
    {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

void nextPermutation(vector<int>& nums) {
     int n = nums.size();
     int i;
     for(i=n-1;i>0;i--)
     {
         if(nums[i]>nums[i-1])
            break;
     }
     if(i==0)
     {
         sort(nums.begin(), nums.end());
         return;
     }

     int j=i-1;
     int mini=INT_MAX;
     for(i=n-1;i>j;i--)
     {
        if(nums[j]<nums[i]) mini = min((nums[i]-nums[j]), mini);
     }

     for(i=n-1;i>j;i--)
         if(nums[i]>nums[j]&&nums[i]-nums[j]==mini)
         {
             swap(nums[i], nums[j]);
             break;
         }

     reverse(nums, j+1, n-1);

}
};