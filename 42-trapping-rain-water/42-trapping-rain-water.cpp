class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size();
        
        vector<int> max_left(n);
        vector<int> max_right(n);
        
        for(int i=0;i<n;i++)
        {
            if(i==0) max_left[i] = 0;
            else
            {
                if(height[i-1]>max_left[i-1])
                    max_left[i] = height[i-1];
                else
                    max_left[i] = max_left[i-1];
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1) max_right[i]=0;
            
            else{
                if(height[i+1]>max_right[i+1])
                    max_right[i] = height[i+1];
                else
                    max_right[i] = max_right[i+1];
            }
        }
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            int min_height = min(max_left[i], max_right[i]);
            
            int additive = min_height >= height[i] ? min_height-height[i]:0;
            res = res + additive;
        }
        
        return res;
    }
};