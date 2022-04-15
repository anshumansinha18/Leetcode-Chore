class Solution {
public:
    string longestPalindrome(string s) {
     int n = s.length();

     int resL=0;
     string res;
     for(int i=0;i<n;i++)
     {
         int l=i;
         int r=i;
         while(l>=0 && r<n && (s[l]==s[r]))
         {
                 if((r-l+1)>resL) {
                     resL=(r-l+1);
                     res = s.substr(l, resL);
                 }
             l--;
             r++;
         }
     }
    for(int i=0;i<n;i++)
    {
        int l=i;
        int r=i+1;
        while(l>=0 && r<n && (s[l]==s[r]))
        {
            if((r-l+1)>resL) {
                resL=(r-l+1);
                res = s.substr(l, resL);
            }
            l--;
            r++;
        }
    }
     return res;
}
};