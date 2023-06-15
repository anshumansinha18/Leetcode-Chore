class Solution {
public:
    string capitalizeTitle(string title) {
        
        int start=0;
           title+=" ";
        int n = title.size();
     
        int i=0;
        int count=0;
        while(i<n){
            if(title[i]==' '){
                if(count>2){
                title[start]=title[start]>='a'&&title[start]<='z'?(char)(title[start]-32):title[start];
                }
                start=i+1;
                count=0;
            }else{
                title[i] = title[i]>='A'&&title[i]<='Z'?(char)(title[i]+32):title[i];
                count++;
            }
            i++;
        }
        
        return title.substr(0, n-1);
    }
};