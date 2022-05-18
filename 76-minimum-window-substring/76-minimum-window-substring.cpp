class Solution {
public:
    
    bool check(vector<int> v1, vector<int> v2)
    {
         for(int i=0;i<256;i++)
            {
             if(v1[i]>0)
                if((v2[i]-v1[i])<0)
                    return false; 
            }
        return true;  
    }
    string minWindow(string s, string t) {
        
        int n1 = s.length();
        int n2 = t.length();
        
        vector<int> v1(256, 0);
        vector<int> v2(256, 0);
        
        for(int i=0;i<n2;i++)
            v1[t[i]]++;
        
        int l=0;
        int r = 0;
        int res=INT_MAX;
        
        int pointer1=0;
        int pointer2=0;
        
        while(r<=n1)
        {
           if(check(v1, v2)){
               if((r-l)<res){
                   res = min(res, r-l);
                   pointer1 = l;
                   pointer2 = r;
               }
               v2[s[l]]--;
               l++;
           }
            else
            {
                v2[s[r]]++;
                r++;
            }
        }
        string p = "";
        for(int i=pointer1;i<pointer2;i++)
            p = p+s[i];
        
        return p;
    }
};