class Solution {
public:
  bool isNumber(string c){
    return (c[0]>='0' && c[0]<='9');
  }

string repeat(string rep, string count){
    string result="";
    int c=stoi(count);
    for(int i=0;i<c;i++)
        result+=rep;
    return result;
}

string decodeString(string s) {

    int n = s.size();
    stack<string> st;
    for(int i=0;i<n;i++){
        if(s[i]==']'){
            string str="";
            //removing alphabets;
            while(!st.empty() && st.top()!="["){
                str = st.top()+str;
                st.pop();
            }
            if(!st.empty()) st.pop();
               //removing numbers:
            string num="";
            while(!st.empty() && isNumber(st.top())){
                num=st.top()+num;
                st.pop();
            }
             st.push(repeat(str, num));

        }else{
            string x = "";
            x+=s[i];
            st.push(x);
        }
    }
    string result="";
    while(!st.empty())
        result = st.top()+result, st.pop();
    return result;
}
};