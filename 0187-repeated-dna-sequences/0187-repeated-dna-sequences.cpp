class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        set<string> res;
        set<string> st;
        int n = s.size();
        int i=0;
        int j=0;
        string x="";
        while(j<n){
            x+=s[j];
            
            if(x.size()==10){
                if(st.count(x))
                    res.insert(x);
                st.insert(x);
                x=x.substr(1);
                i++;
            }
            j++;
        }
        for(auto it: res){
            result.push_back(it);
        }
        return result;
    }
};