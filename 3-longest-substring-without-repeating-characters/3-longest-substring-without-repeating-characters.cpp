class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        if(n==0) return 0;
        
        int l = 0;
        int r = 0;
        
       vector<int> v(256, -1);
        int max_len = 1;
        
    while(r<n)
    {
        if(v[s[r]]!=-1)
        {
            if(v[s[r]]>=l && v[s[r]]<=r)
                l = v[s[r]]+1;
        }
        
        v[s[r]] = r;
        int len = r-l+1;
        max_len = max(max_len, len);
        r++;
    }
        
        return max_len;
    }
};