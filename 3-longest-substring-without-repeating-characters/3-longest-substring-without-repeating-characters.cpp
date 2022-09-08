class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        if(n==0) return 0;
        
        int l = 0;
        int r = 0;
        
        unordered_map<int, int> m;
        int max_len=1;
        int len;
        while(r<n)
        {
            if(m[s[r]]>0)
            {
                //rep
                max_len = max(max_len, len);
                
                while(s[l]!=s[r] && l<n)
                {
                    m[s[l]]--;
                    l++;
                }
                m[s[l]]--;
                l++;
            }
            else
            {
                
                //no rep
                m[s[r]]++;
                r++;
                len = r-l;
                
            }
        }
        
        max_len = max(max_len, len);
        return max_len;
    }
};