class Solution {
public:
    
    int findMax(vector<int> v)
    {
        int maxim = 0;
        
        for(int i=0;i<v.size();i++)
            maxim = max(maxim, v[i]);
        
        return maxim;
    }
    
    int characterReplacement(string s, int k) {
        int n = s.length();
        
        int l=0,r=0;
        vector<int> v(27, 0);
        int max_len = 1;
        while(r<n)
        {
            v[int(s[r] - 65)]++;
            
            int len = r-l+1;
            
            int maxim = findMax(v);
            int pos = len - maxim;
            
            if(pos<=k)
            {
                max_len = max(max_len, len);
                r++;
            }
            else
            {
                v[int(s[l]-65)]--;
                v[int(s[r]-65)]--;
                l++;
            }
            
            
        }
        
        return max_len;
        
    }
};