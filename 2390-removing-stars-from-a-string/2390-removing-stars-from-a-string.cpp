class Solution {
public:
    string removeStars(string s) {
        
        int n = s.size();
        vector<char> st;
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                st.push_back(s[i]);
            }else{
                st.pop_back();
            }
        }
        
        string res="";
        for(auto it: st){
            res+=it;
        }
        return res;
    }
};