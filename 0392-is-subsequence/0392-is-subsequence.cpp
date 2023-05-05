class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n1 = s.size();
        int n2 = t.size();
        
        int i=0;
        for(int j=0;j<n2;j++){
            if(s[i]==t[j])
                i++;
        }
        
        if(i==n1)
            return true;
        
        return false;
    }
};