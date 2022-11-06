class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> rb(n, n);
        vector<int> lb(n, -1);
        
        stack<int> st;
        
        //right boundary code
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                rb[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
      
        //left boundary code
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                lb[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
       
        
        
        int maxArea = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int area = (rb[i]-lb[i] - 1) * heights[i];
            if(area>maxArea) maxArea = area;
            
        }
        return maxArea;
        
    }
};