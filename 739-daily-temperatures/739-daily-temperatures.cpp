class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int>& arr = temperatures;
        vector<int> ans(n);
        
        stack<int> st;
        
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]<arr[i])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            
            if(arr[i]>arr[i-1])
                ans[i-1] = 1;
            else
                st.push(i-1);
        }
        
        return ans;
    }
};