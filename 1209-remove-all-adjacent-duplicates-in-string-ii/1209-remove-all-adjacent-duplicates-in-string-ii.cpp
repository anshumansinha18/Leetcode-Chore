class Solution {
public:
    
    string repeatString(char c, int count){
        string res="";
        while(count){
            res+=c;
            count--;
        }
        
        return res;
    }
    string removeDuplicates(string s, int k) {
        
        stack<char> st1;
        stack<int> st2;
        int n = s.size();
        for(int i=0;i<n;i++){
            
            if(!st1.empty() && s[i]==st1.top()){
                int count=st2.top()+1;
                st2.pop();
                st2.push(count);
            }
            else{
                st1.push(s[i]);
                st2.push(1);
            }
            
            if(st2.top()==k){
                st1.pop();
                st2.pop();
            }
        }
        
        string result="";
        stack<string> tempSt;
        while(!st1.empty()){
            char c = st1.top();
            int rep = st2.top();
            tempSt.push(repeatString(c, rep));
            st1.pop();
            st2.pop();
        }
        
        while(!tempSt.empty()){
            result+=tempSt.top();
            tempSt.pop();
        }
       
        return result;
    }
};