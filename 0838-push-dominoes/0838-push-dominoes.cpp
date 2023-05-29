class Solution {
public:
    string pushDominoes(string dominoes) {
     string s="L";
     s+=dominoes;
     s+="R";
     string res="";
     int n = s.size();
     int i=0;
     int j=1;
     while(i<n && j<n){
         int start=i;
         int end=j;
         if(s[i]==s[j]){
             for(int k=start;k<end;k++)
                 res+=s[i];
             i=j;j=i+1;
         }
         else if(s[i]=='L' && s[j]=='R'){
             for(int k=start;k<end;k++)
                 res+=s[k];
             i=j,j=i+1;
         }else if(s[i]=='R' && s[j]=='L'){
             for(int k=start;k<end;k++){
                 if((i+j)%2==0){
                     if(k<(i+j)/2)
                         res+=s[i];
                     else if(k>(i+j)/2)
                         res+=s[j];
                     else
                         res+=s[k];
                 }else{
                     if(k<=(i+j)/2)
                         res+=s[i];
                     else
                         res+=s[j];
                 }
             }
             i=j,j=i+1;
         }else{
             j++;
         }
     }
     string finalRes="";
     for(int i=1;i<res.size();i++){
         finalRes+=res[i];
     }
    return finalRes;
}
};