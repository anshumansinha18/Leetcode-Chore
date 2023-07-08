class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char> st;
        int n = num.size();
        for(int i=0;i<n;i++){
            
            while( k>0&& !st.empty() && st.top()>num[i]){
                st.pop();
                k--;
            }
            
            st.push(num[i]);
            
            if(st.size()==1 && num[i]=='0'){
                st.pop();
            }
        }
        while( k>0&&!st.empty()){
            st.pop();
            k--;
        }
        string result="";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        
       
    
        return result==""?"0":result;
    }
};