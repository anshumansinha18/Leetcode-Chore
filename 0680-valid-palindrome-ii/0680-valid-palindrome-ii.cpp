class Solution {
public:
    bool validPalindrome(string s) {
        
        int i=0;
        int j=s.size()-1;
        int n = s.size();
        int count=1;
        bool res=true;
        
       while(i<j && s[i]==s[j]){
           i++;
           j--;
       }
        
        int tempI = i;
        int tempJ = j;
       while(i<j && s[i]==s[j-1]){
           i++;
           j--;
       
       }
        while(tempI<tempJ && s[tempI+1]==s[tempJ]){
            tempI++;
            tempJ--;
        }
        
       if(i>=j || tempI>=tempJ)
           return true;
        else return false;
        
       
    }
};