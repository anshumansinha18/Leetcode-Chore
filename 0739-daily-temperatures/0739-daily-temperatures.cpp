class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> st;
        vector<int> &arr = temperatures;
        vector<int> result(arr.size());
        for(int i=0;i<arr.size();i++){
            
            while(!st.empty() && arr[i]>arr[st.top()])
            {
                result[st.top()]=i-st.top();
                st.pop();
            }
            
            st.push(i);
        }
        
        return result;
    }
};