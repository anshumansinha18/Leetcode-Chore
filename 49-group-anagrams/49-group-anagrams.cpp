class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
       map< map<int, int>, vector<string> > m;
        
        int n = strs.size();
        
        for(int i=0;i<n;i++)
        {
            map<int, int> m2;
            for(int j=0;j<strs[i].size();j++)
                m2[strs[i][j]]++;
            
            m[m2].push_back(strs[i]);
            
        }
        
        vector<vector<string>> v;
        for(auto it: m)
        {
            v.push_back(it.second);
        }
        
        return v;
    }
};