class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        
        int i=0, j=0;
        unordered_map<int, int> m;
        int res=0;
        
        while(j<n)
        {
            if(m[s[j]]==0)
            {
                m[s[j]]++;
                j++;
                res = max(res, (j-i));
            }
            else
            {
                while(s[i]!=s[j] && i<n){
                    m[s[i]]--;
                    i++;
                 }
                m[s[i]]--;
                i++;
              }
        }
        
        return res;
    }
};