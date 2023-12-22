class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n1=pushed.size();
        int n2=popped.size();
        
        int i=0;
        int j=0;
        stack<int> st;
        
        for(int i=0;i<n1;i++){
            st.push(pushed[i]);
            
            while(!st.empty() && j<n2 && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};