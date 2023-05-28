class Solution {
public:
    
    
    bool compare(vector<int>& vec1, vector<int>& vec2){
        for(int i=0;i<26;i++){
            if(vec1[i]!=vec2[i])
                return false;
        }
        
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        
        int n1 = s.size();
        int n2 = p.size();
        vector<int> m(26, 0);
        vector<int> rm(26, 0);
        vector<int> res;
        
        
        for(int i=0;i<n2;i++){
            m[p[i]-97]++;
        }
        
        int i=0;
        for(int j=0;j<n1;j++){
            rm[s[j]-97]++;
            
            if(compare(m, rm)){
                cout<<i<<endl;
                cout<<j;
                res.push_back(i);
            }
            
            if(j-i==n2-1){
                rm[s[i]-97]--;
                i++;
            }
        }
        
        return res;
    }
};