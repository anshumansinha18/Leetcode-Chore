class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        for(int i=0;i<n;i++){
            m1[s[i]]=t[i];
            m2[t[i]]=s[i];
        }
        
        string temp1 = "";
        string temp2 = "";
        for(int i=0;i<n;i++){
            temp1+=m1[s[i]];
            temp2+=m2[t[i]];
        }
        cout<<temp1<<" "<<temp2<<endl;
        if(s==temp2 && t==temp1)
            return true;
        else return false;
  
    }
};