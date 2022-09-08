class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int l=0;
        int r = n-1;
        
        int max_left = height[0];
        int max_right = height[n-1];
        
        int sum=0;
        while(l<r)
        {
            if(max_left<=max_right)
            {
                l++;
                if(l>=r) break;
                int w = min(max_left, max_right) - height[l]; cout<<w<<" ";
                if(w<0) w=0;
                
                sum = sum + w;
                if(height[l]>max_left)
                    max_left = height[l];
                
                
            }
            else
            {
                r--;
                if(l>=r) break;
                int w = min(max_left, max_right) - height[r];
                if(w<0) w=0;
                
                sum = sum + w;
                if(height[r] > max_right)
                    max_right = height[r];
            }
        }
        
        return sum;
        
    }
};