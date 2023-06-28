class Solution {
public:
    
     bool compare(unordered_map<char, int>& m1, unordered_map<char, int>& m2){

        for(auto it: m2){
            if(it.second > m1[it.first])
                return false;
        }

        return true;
    }
    string minWindow(string s, string t) {

        int i=0;
        int j=0;
        if(t.size()>s.size()) return "";
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        int min_l = INT_MAX;

        for(int i=0;i<t.size();i++){
            m2[t[i]]++;
        }

        int l=-1;
        int h=-1;

        while(j<s.size()){
            m1[s[j]]++;

            if(compare(m1, m2)){
                if(min_l>(j-i+1)){
                    l=i;
                    h=j;
                    min_l=(j-l+1);
                }
                m1[s[i]]--;
                i++;
                m1[s[j]]--;
            }
            else j++;
        }
       cout<<l<<" "<<h<<endl;
        if(l==-1 || h==-1) return "";
       string res="";
        for(int i=l;i<=h;i++)
            res+=s[i];
        
        return res;

    }
};