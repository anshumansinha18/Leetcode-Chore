class Solution {
public:
    int lengthOfLastWord(string s) {
         int n = s.size();
        
         int end=n-1;
         while(s[end]==' '){
             end--;
         }
        
         string res="";
         for(int i=end;i>=0 && s[i]!=' ';i--){
             res+=s[i];
         }
         cout<<res<<endl;
         return res.size();
        
    }
};