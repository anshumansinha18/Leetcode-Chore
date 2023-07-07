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

string reverse(string s){
    int start=0;
    int end = s.size()-1;
    while(start<end){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }

    return s;
}
string decodeString(string s) {

    int n = s.size();
    stack<string> st;
    for(int i=0;i<n;i++){
        if(s[i]==']'){
            // stack<string> st1;
            string str="";
            //removing alphabets;
            while(!st.empty() && st.top()!="["){
                str = st.top()+str;
                st.pop();
            }
            if(!st.empty()) st.pop();
//                 //removing numbers:
            string num="";
            while(!st.empty() && isNumber(st.top())){
                num+=st.top();
                st.pop();
            }

            // string str="";
            // while(!st1.empty()){
            //     str+=st1.top();
            //     st1.pop();
            // }
//            cout<<num<<" XXX"<<str<<endl;
            num = reverse(num);
             st.push(repeat(str, num));


        }else{
            string x = "";
            x+=s[i];
            st.push(x);
        }
    }
    string result="";
    stack<string> res;
    while(!st.empty()){
        res.push(st.top());
        st.pop();
    }

    while(!res.empty()){
        result+=res.top();
        res.pop();
    }
    return result;
}
};