class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        
        map<char, int> m1;
        for(int i=0;i<n2;i++){
            m1[p[i]]++;
        }
        int i=0;
        map<char, int> m2;
        vector<int> res;
        for(int j=0;j<n1;j++){
            m2[s[j]]++;
            
            if((j-i+1)==n2){
                if(m1==m2)
                   res.push_back(i);
                
                m2[s[i]]--;
                if(m2[s[i]]==0) m2.erase(s[i]);
                i++;
            }
        }
        
        return res;
    }
};