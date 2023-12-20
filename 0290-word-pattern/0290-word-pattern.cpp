class Solution {
public:
    bool wordPattern(string pattern, string s) {
         s+=' ';
        int n1=pattern.size();
        int n2=s.size();
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        string res="";
       
        int j=0;
        for(int i=0;i<n2;i++){
            if(s[i]==' '){
              
               if((m1.find(pattern[j])!=m1.end() && m1[pattern[j]]!=res) || (m2.find(res)!=m2.end() && m2[res]!=pattern[j])){
                   return false;
               }
                   m1[pattern[j]]=res;
                   m2[res]=pattern[j];
                   j++;
                   
             
                res="";
            }else{
                res+=s[i];
            }
        }
        return !(j<n1);
    }
};