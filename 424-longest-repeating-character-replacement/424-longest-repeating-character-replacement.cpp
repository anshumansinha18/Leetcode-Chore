class Solution {
public:
    
    int calcMax(vector<int> c)
    {
        int n = c.size();
        int maxf = INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxf = max(maxf, c[i]);
        }
        return maxf;
    }
    
    int characterReplacement(string s, int k) {
        
        int i=0,j=0;
        int n = s.length();
        int res=0;
        vector<int> m(26,0);
        
        while(j<n)
        {
            m[s[j]-65]++;
            int maxf = calcMax(m);
            int wl = j-i+1;
            if(wl-maxf<=k)
            {
                res = max(res, wl);
                j++;
            }
            else
            {
                m[s[i]-65]--;
                i++;
                m[s[j]-65]--;
            }
        }
        
        return res;
        
    }
};