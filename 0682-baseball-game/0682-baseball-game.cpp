class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        int n = operations.size();
        stack<int> st;
        int sum=0;
        for(int i=0;i<n;i++){
            if(operations[i]=="+"){
                int x=st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x+y);
            }else if(operations[i]=="D"){
                int x = 2*st.top();
                st.push(x);
            }else if(operations[i]=="C"){
                st.pop();
            }else{
                st.push(stoi(operations[i]));
            }
        }
        
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        
        return sum;
    }
};