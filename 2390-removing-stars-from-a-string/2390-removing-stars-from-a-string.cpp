class Solution {
public:
    string removeStars(string s) {
        
        stack<int> st;
  
        
        int n = s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]=='*')
                st.pop();
            else
                st.push(s[i]);
        }
        
        string res="";
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        int j=res.size()-1;
        string result="";
        while(j>=0){
            result+=res[j--];
        }
        return result;
    }
};