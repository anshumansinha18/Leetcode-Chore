class Solution {
public:
    int trap(vector<int>& height) {
     int n = height.size();
     int max_left = height[0];
     int max_right = height[n-1];

     int l = 0;
     int r = n-1;

     int trapWater = 0;
     
     vector<int> res(n);
     while(l<=r)
     {
         if(max_left<=max_right)
         {
             trapWater += (max_left - height[l])<0?0:(max_left-height[l]);
             max_left = max(max_left, height[l]);
             l++;
         }
         else
         {
             trapWater += (max_right - height[r])<0?0:(max_right-height[r]);
             max_right = max(max_right, height[r]);
             r--;
         }
     }

     return trapWater;
     
}
};