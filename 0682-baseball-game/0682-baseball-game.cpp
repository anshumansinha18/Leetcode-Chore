class Solution {
public:
    bool isOperation(string s){
        return s=="C" || s=="D" || s=="+";
    }
    
    void performOperation(stack<string>& st, string op){
        if(op=="+"){
            int a = stoi(st.top());
            st.pop();
            int b = stoi(st.top());
            st.push(to_string(a));
            st.push(to_string(a+b));
        }
        else if(op=="D"){
            int a = stoi(st.top());
            st.push(to_string(a*2));
        }else if(op=="C"){
            st.pop();
        }
    }
    int calPoints(vector<string>& operations) {
        stack<string> st;
        
        for(int i=0;i<operations.size();i++){
            if(isOperation(operations[i])){
                performOperation(st, operations[i]);
            }else{
                st.push(operations[i]);
            }
        }
        int res=0;
        while(!st.empty()){
            res=res+stoi(st.top());
            st.pop();
        }
        
        return res;
        
        
    }
};