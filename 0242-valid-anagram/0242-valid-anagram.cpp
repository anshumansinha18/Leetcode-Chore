class Solution {
public:
    bool isAnagram(string s, string t) {
          int n = s.size();
        int m = t.size();
        
        unordered_map<int, int> hashM;
        for(int i=0;i<n;i++) 
            hashM[s[i]]++;
        
        for(int i=0;i<m;i++)
            hashM[t[i]]--;
        
        for(auto it:hashM)
            if(it.second!=0)
                return false;
        
        return true;
    }
};