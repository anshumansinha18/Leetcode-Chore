class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        
        for(int i=0;i<s.size();i++){
            m1[s[i]]=t[i];
            m2[t[i]]=s[i];
        }
        
        string x = "";
        string y="";
        for(auto it: s) x+=m1[it];
        for(auto it: t) y+=m2[it];
        return x==t && y==s;
        
        
    }
};