class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size();
        int n2=needle.size();
        string temp="";
        int i=0;
        for(int j=0;j<n1;j++){
            
            temp+=haystack[j];
            
            if(temp.size()==n2){
                if(temp==needle){
                    return i;
                }
                temp=temp.substr(1);
                i++;
            }
        }
        
        return -1;
    }
};