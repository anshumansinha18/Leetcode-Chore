class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size()) return false;
        unordered_map<char, int> m;
        
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            m[t[i]]--;
        }
        
        for(auto it: m){
            if(it.second!=0) return false;
        }
        return true;
        
    }
};