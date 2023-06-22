class Solution {
public:
    int minFlips(string s) {
        
        int n1 = s.size();
        s+=s;
        int n2 = s.size();
        int len1=0, len2=0;
        int result=INT_MAX;
        int j=0;
        for(int i=0;i<n2;i++){
            
            if(i%2==0){
                if(s[i]=='0') len1++;
                else len2++;
            }else{
                if(s[i]=='1') len1++;
                else len2++;
            }
            
            if(i-j+1==n1){
                result = min(result, min(len1, len2));
                if(j%2==0){
                    if(s[j]=='0') len1--;
                    else len2--;
                }else{
                    if(s[j]=='1') len1--;
                    else len2--;
                }
                j++;
            }
        }
        
        return result;
    }
};