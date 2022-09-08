class Solution {
public:
    
    bool check(vector<int> m1, vector<int> m2)
    {
        
        for(int i=0;i<26;i++)
        {
            if(m1[i]!=m2[i])
                return false;
        }
        
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> m1(26, 0);
        vector<int> m2(26, 0);
        
        int n1 = s1.length();
        int n2 = s2.length();
        
        if(n1>n2)
            return false;
        
        int l=0;
        int r=0;
        
        for(int i=0;i<n1;i++)
            m1[s1[i]-97]++;
        
        while(r<n1)
        {
            m2[s2[r]-97]++;
            r++;
        }
        
        if(check(m1, m2)) return true;
        while(r<n2)
        {
            m2[s2[l]-97]--;
            m2[s2[r]-97]++;
            l++;
            r++;
            if(check(m1, m2))
           {
               return true;
           }
           
        }
        
        return false;
    }
};