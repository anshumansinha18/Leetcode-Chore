class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        
        int l = 0;
        int r = n-1;
        int max_area = 0;
        
        while(l<r){
            max_area = max(max_area, min(height[l], height[r])*(r-l));
            if(height[l]<height[r]){
                l++;
            }else if(height[l]>height[r])
                r--;
            else{
                l++;
                r--;
            }
        }
        
        return max_area;
    }
};