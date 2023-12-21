class Solution {
public:
    
    bool isPalindrome(string s){
        int start=0;
        int end=s.size()-1;
        
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    int maxProduct(string s) {
        
        int n=s.size();
        vector<pair<int, int>> bucket;
        for(int i=1;i<(1<<n);i++){
            string res="";
            for(int j=0;j<n;j++){
                if(i&(1<<(n-j-1))){
                    res+=s[j];
                }
            }
            if(isPalindrome(res)) bucket.push_back(make_pair(res.size(), i));
        }
        int maxProd=1;
        
        for(int i=0;i<bucket.size();i++){
            for(int j=i+1;j<bucket.size();j++){
                if(((bucket[i].second)&(bucket[j].second))==0){
                  maxProd=max(maxProd, bucket[i].first*bucket[j].first);
                }
            }
        }
        return maxProd;
    }
};