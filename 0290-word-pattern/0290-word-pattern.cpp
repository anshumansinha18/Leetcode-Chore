class Solution {
public:
bool wordPattern(string pattern, string s) {

    unordered_map<string, char> m1;
    unordered_map<char, string> m2;
    s+=" ";
    int n2 = s.size();
    int n1 = pattern.size();
    int j=0;
    string res="";
    for(int i=0;i<n2;i++){
        if(s[i]==' '){
            if((m1[res]!=0 && m1[res]!=pattern[j]) || (m2[pattern[j]]!="" && m2[pattern[j]]!=res))
                return false;
            m1[res]=pattern[j];
            m2[pattern[j++]] = res;
            res="";
        }else{
            res+=s[i];
        }
    }
    
    if(j<n1)
        return false;
    return true;
}
};