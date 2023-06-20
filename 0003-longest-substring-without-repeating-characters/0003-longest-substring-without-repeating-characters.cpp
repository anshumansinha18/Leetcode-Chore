class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> v(256, -1);
        
        int n=s.size();
        int j=0, max_len = 0;
        for(int i=0;i<n;i++){
          
            if(v[s[i]]!=-1 && v[s[i]]>=j){
                j=v[s[i]]+1;
            }
            
            v[s[i]]=i;
            max_len = max(max_len, i-j+1);
            
        }
        
        return max_len;
    }
};