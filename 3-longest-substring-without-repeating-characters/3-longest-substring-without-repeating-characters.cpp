class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      
        vector<int> index(256, -1);
        
        int n = s.length();
        int i=0,j=0;
        int res=0;
        while(j<n)
        {
            if(index[s[j]]==-1 || index[s[j]]<i)
            {
                index[s[j]] = j;
                j++;
                res = max(res, (j-i));
            }
            else
            {
                i = index[s[j]]+1;
                index[s[j]]=-1;
            }
        }
        return res;
    }
};