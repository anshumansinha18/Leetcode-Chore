class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
       int max_l = height[0];
        int max_r = height[n-1];
        
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<=r){
            int x = min(max_l, max_r);
            if(max_l<=max_r){
               x-=height[l];
                ans+= x<0?0:x;
                max_l = max(max_l, height[l]);
                l++;
            }else{
                x-=height[r];
                ans+= x<0?0:x;
                max_r = max(max_r, height[r]);
                r--;
            }
        }
        
        return ans;
    }
};