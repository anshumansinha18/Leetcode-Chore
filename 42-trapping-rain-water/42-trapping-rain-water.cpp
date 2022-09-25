class Solution {
public:
    int trap(vector<int>& height) {
         
        int n = height.size();
        
        vector<int> max_left(n);
        vector<int> max_right(n);
        int total = 0;
        
        for(int i=1;i<n;i++)
            max_left[i] = max(height[i-1], max_left[i-1]);
        
        for(int i=n-2;i>=0;i--)
            max_right[i] = max(height[i+1], max_right[i+1]);
        
        for(int i=0;i<n;i++){
            int x = min(max_left[i], max_right[i]) - height[i];
            if(x>0)
                total += x;
        }
        
        return total;
    }
};