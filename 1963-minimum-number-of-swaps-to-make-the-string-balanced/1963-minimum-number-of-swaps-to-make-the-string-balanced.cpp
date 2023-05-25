class Solution {
public:
    int minSwaps(string s) {
        
        int n = s.size();
        int extra = 0;
        int maxExtra = 0;
        for(int i=0;i<n;i++){
            if(s[i]==']')
                extra++;
            else
                extra--;
            maxExtra = max(extra, maxExtra);
        }
        
        return (maxExtra+1)/2;
    }
};