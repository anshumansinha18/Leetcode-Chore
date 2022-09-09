class Solution {
public:
    
    bool check(vector<int> m1, vector<int> m2)
    {
            for(int i=0;i<256;i++)
            {
                if(m1[i]>0)
                {
                    if(m1[i]>m2[i])
                        return false;
                }
                    
            }
        return true;
    }
    
    string minWindow(string s, string t) {
        
        int n1 = s.size();
        int n2= t.size();
        string res="";
        
        if(n1<n2)
            return res;
        
        int l=0;
        int r=0;
        
        vector<int> m1(256, 0);
        vector<int> m2(256, 0);
        
        for(int i=0;i<n2;i++)
            m1[t[i]]++;
        
        while(r<n2)
        {
           m2[s[r]]++;
            r++;
        }
        
        int min_len=INT_MAX;
        int len=0;
        int ans1=-1;
        int ans2=-1;
        if(check(m1, m2)){
            len=r-l;
            if(len<min_len)
            {
                ans1=l;
                ans2=r-1;
                min_len = len;
            }
        }
        
        while(r<n1)
        {
            m2[s[r]]++;
            if(!check(m1, m2))
            {
                r++;
            }
            else
            {
                len = r-l+1;
                if(len<min_len)
                {
                    ans1=l;
                    ans2=r;
                    min_len = len;
                }
                m2[s[l]]--;
                l++;
                m2[s[r]]--;
            }
        }
        
        if(ans1==-1 || ans2 == -1) return "";
        for(int i=ans1;i<=ans2;i++)
            res += s[i];
        
        return res;
        
    }
};