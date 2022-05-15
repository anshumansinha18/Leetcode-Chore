class Solution {
public:
    
  
    int characterReplacement(string s, int k) {
        
        int i=0,j=0;
        int n = s.length();
        int res=0;
        unordered_map<int, int> m;
        int maxf=0;
        while(j<n)
        {
            maxf = max(maxf, ++m[s[j]]);
            int wl = j-i+1;
            if(wl-maxf<=k)
            {
                res = max(res, wl);
                j++;
            }
            else
            {
                m[s[i]]--;
                i++;
                m[s[j]]--;
            }
        }
        
        return res;
        
    }
};