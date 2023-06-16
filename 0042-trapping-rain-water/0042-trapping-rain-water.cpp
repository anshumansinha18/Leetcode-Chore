class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1], height[i-1]);
        }
        
        for(int j=n-2;j>=0;j--){
            right[j] = max(right[j+1], height[j+1]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int x = min(left[i], right[i])-height[i];
            ans+= (x<0)?0:x;
        }
        
        return ans;
    }
};