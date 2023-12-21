class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> left;
        unordered_map<char, int> right;
        
        unordered_set<string> res;
        int n = s.size();
        for(int i=0;i<n;i++){
            right[s[i]]++;
        }
        
        for(int i=0;i<n;i++){
            right[s[i]]--;
            
            for(int j=0;j<26;j++){
                char charName = char('a'+j);
                if(left[charName] && right[charName]){
                    string x = "";
                     x+=charName;
                      x+=s[i];
                     x+=charName;
                    res.insert(x);
                }
            }
            
            left[s[i]]++;
        }
        
        return res.size();
        
    }
};