class Solution {
public:
    string capitalizeTitle(string title) {
        
        int n=title.size();
        int j=0;
        for(int i=0;i<n;i++){
            
            
            if(title[i]==' '){
                int len = i-j;
                
                if(len>=3){
                    title[j] = toupper(title[j]);
                    
                }
                j=i+1;
            }else{
                title[i] = tolower(title[i]);
            }
        }
        if(title.size()-j>=3) title[j]=toupper(title[j]);
        return title;
    }
};