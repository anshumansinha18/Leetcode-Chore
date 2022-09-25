class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        int l=0;
        int r=n-1;
        
        int max_left=height[l];
        int max_right=height[r];
        int i=l;
        int total=0;
        
        while(l<r)
        {
             int x = min(max_left, max_right) - height[i];
            if(x>0)
                total += x;
            max_left = max(height[l], max_left);
            max_right = max(height[r], max_right);
            
            if(max_left<=max_right)
            {
                l++;
                i=l;
            }
            else
            {
                r--;
                i=r;
            }
        }
        
        return total;
    }
};