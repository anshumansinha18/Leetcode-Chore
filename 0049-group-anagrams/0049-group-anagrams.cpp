class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<map<char, int>, vector<string>> m1;
        
        int n = strs.size();
        
        for(int i=0;i<n;i++){
            map<char, int> m2;
            for(int j=0;j<strs[i].size();j++){
                m2[strs[i][j]]++;
            }
            
            m1[m2].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        for(auto it: m1){
            res.push_back(it.second);
        }
        
        return res;
    }
};