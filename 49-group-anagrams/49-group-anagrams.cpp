class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<map<char, int>, vector<string>> m;
        
        int n = strs.size();
        for(int i=0;i<n;i++)
        {
                map<char, int> m1;
                for(int j=0;j<strs[i].size();j++)
                    m1[strs[i][j]]++;
                
                m[m1].push_back(strs[i]);
        }
        
        vector<vector<string>> vec;
        for(auto it : m)
        {
           vec.push_back(it.second);
        }
        
        return vec;
    }
};