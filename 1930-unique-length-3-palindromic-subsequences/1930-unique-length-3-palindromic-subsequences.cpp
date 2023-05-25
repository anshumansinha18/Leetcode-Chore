class Solution {
public:
  
int countPalindromicSubsequence(string s) {
    unordered_map<char, int> r;
    unordered_map<char, int> l;
    unordered_set<string> setString;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        r[s[i]]++;
    }

    for (int i = 0; i < n; i++) {
        r[s[i]]--;
        if (i != 0) {
            for (char j = 'a'; j <= 'z'; j++) {
                if(l[j] && r[j]) {
                    string res = "";
                    res += j;
                    res += s[i];
                    res += j;
                    setString.insert(res);
                }
            }
        }
        l[s[i]]++;

    }

    return setString.size();
}
};