class Solution {
public:
    
   
    int strStr(string haystack, string needle) {
        
        int n1 = haystack.size();
        int n2 = needle.size();
        string res="";
        
     
        int i=0;
        for(int j=0;j<n1;j++){
           res+=haystack[j];
            
            if(res==needle)
                return i;
            if(j-i==n2-1){
                i++;
                res="";
                for(int k=i;k<=j;k++)
                    res+=haystack[k];
            }
        }
            return -1;
    }
};