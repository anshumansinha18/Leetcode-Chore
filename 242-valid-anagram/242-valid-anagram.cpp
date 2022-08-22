class Solution {
public:
    bool isAnagram(string s, string t) {
        
        
        if(s.size()!=t.size()) return false;
        
        unordered_map<char, int> countChars;
        
        for(int i=0;i<s.size();i++)
        {
            countChars[s[i]]++;
            countChars[t[i]]--;
        }
        
        for(auto it: countChars)
            if(it.second)
                return false;
        
        return true;
      
    }
};