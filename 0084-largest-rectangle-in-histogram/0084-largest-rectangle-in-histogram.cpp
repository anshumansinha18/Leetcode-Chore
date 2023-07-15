class Solution {
public:
    
    vector<int> generateNSELeft(vector<int> &nums){
        stack<int> st;
        int n = nums.size();
        vector<int> res(n, -1);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]<nums[st.top()]){
                res[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
    
    vector<int> generateNSERight(vector<int> &nums){
        stack<int> st;
        
        int n = nums.size();
        vector<int> res(n, n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<nums[st.top()]){
                res[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> nseR = generateNSERight(heights);
        vector<int> nseL = generateNSELeft(heights);
        
        int n = heights.size();
 
        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea = max((nseR[i]-nseL[i]-1)*heights[i], maxArea);
        }
        
        return maxArea;
    }
};