class Solution {
public:
    
    bool isNumber(char c){
        return c>='0' && c<='9';
    }
    
    string repeat(int num, string str){
        string rep="";
        for(int i=0;i<num;i++){
            rep+=str;
        }
        
        return rep;
    }
    
    void addToStack(string str, stack<char>& st){
        int n = str.size();
        for(int i=0;i<n;i++){
            st.push(str[i]);
        }
    }
    string decodeString(string s) {
        
        int n = s.size();
        stack<char> st;
        string temp="";
        for(int i=0;i<n;i++){
            
            if(s[i]==']'){
                //keep popping and creating a string until you see a [
                string str = "";
                
                while(!st.empty() && st.top()!='['){
                    str=st.top()+str;
                    st.pop();
                }
                    
                //pop([)
                st.pop();     
                //keep popping and creating a number until your stack becomes empty or 
                //you find a character.
                string num="";
                while(!st.empty() && isNumber(st.top())){
                    num=st.top()+num;
                    st.pop();
                }
                
                // cout<<str<<" "<<num<<endl;
                
                //perform operation.
                string rep = repeat(stoi(num), str);
                
                addToStack(rep, st);
            }else{
                st.push(s[i]);
            }
        }
        string result="";
        while(!st.empty()){
            result=st.top()+result;
            st.pop();
        }
        return result;
        
    }
};