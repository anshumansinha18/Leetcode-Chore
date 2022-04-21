class Solution {
public:
    
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<map<char, int>, vector<string>> m1;

    unsigned int n = strs.size();
    for(int i=0;i<n;i++)
    {
        map<char, int> m;
        for(int j=0;j<strs[i].length();j++)
            m[strs[i][j]]++;

        m1[m].push_back(strs[i]);
    }

    vector<vector<string>> res;
    for(auto it = m1.begin();it!=m1.end();it++)
    {
        res.push_back(it->second);
    }
    return res;
}
};