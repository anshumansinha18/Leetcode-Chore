class Solution {
public:
    
    bool checkPal(string s){
        int start=0;
        int end = s.size()-1;
        
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        
        return true;
    }
    int maxProduct(string s) {
        
        int n = s.size();
        vector<pair<int, int>> vec;
        for(int i=1;i<(1<<n);i++){
            string check="";
            for(int j=0;j<n;j++){
                int x = 1<<j;
                if((i&x)!=0){
                    check+=s[j];
                }
            }
            if(checkPal(check)){ 
  
                vec.push_back(make_pair(i, check.size()));}
        }
        
        int maxProd=0;
        for(int i=0;i<vec.size()-1;i++){
            for(int j=i+1;j<vec.size();j++){
            
                if((vec[i].first&vec[j].first)==0){
                    maxProd = max(maxProd, vec[i].second*vec[j].second);
                }
            }
        }
        
        return maxProd;
    }
};