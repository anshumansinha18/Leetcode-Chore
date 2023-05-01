class Solution {
public:
    bool isAnagram(string s, string t) {
          int n = s.size();
          int m = t.size();
         if(m!=n) return false;
        unordered_map<int, int> hashM;
        for(int i=0;i<n;i++){
            hashM[s[i]]++;
            hashM[t[i]]--;
        }
        
      
        
        for(auto it:hashM)
            if(it.second)
                return false;
        
        return true;
    }
};