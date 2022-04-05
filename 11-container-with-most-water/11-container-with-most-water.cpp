class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int low = 0;
        int high = height.size()-1;
        int maxArea = -1;
        while(low<high)
        {
            int lh = height[low];
            int rh = height[high];
            int heightOfRect = min(lh, rh);
            int length = high-low;
            
            int area = heightOfRect*length;
            maxArea = max(area, maxArea);
            if(lh<rh) low++;
            else high--;
        }
        
        return maxArea;
    }
};