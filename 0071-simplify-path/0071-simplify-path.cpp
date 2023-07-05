class Solution {
public:
    string simplifyPath(string path) {
       int i=1;
        if(path[path.size()-1]!='/') path+='/';
        int n = path.size();
        
        stack<string> st;
        string res="";
        while(i<n){
            if(path[i]=='/'){
                if(res==".."){
                    if(!st.empty()) st.pop();
                }
                else if(res!="" && res!="."){
                    st.push(res);
                }
                i++;
                res="";
            }else{
                res+=path[i];
                i++;
            }
        }
        
        stack<string> rev;
        
        while(!st.empty()){
            rev.push(st.top());
            st.pop();
        }
        string result="/";
        while(!rev.empty()){
            result+=rev.top();
            if(rev.size()!=1) result+='/';
            rev.pop();
        }
     
        return result;
    }
};