class Solution {
public:
    bool validPalindrome(string s) {
        
        int i1=0;
        int j1=s.size()-1;
        int n = s.size();
        int count=1;
        bool res=true;
        
       while(i1<j1 && s[i1]==s[j1])  i1++,j1--;
        
        int i2 = i1, j2=j1;
        
       while(i1<j1 && s[i1]==s[j1-1]) i1++,j1--;
       
        while(i2<j2 && s[i2+1]==s[j2]) i2++,j2--;
        
        
       if(i1>=j1 || i2>=j2)
           return true;
        else return false;
        
       
    }
};