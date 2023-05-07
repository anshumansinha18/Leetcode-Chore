#include <bits/stdc++.h>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int min_size = INT_MAX;
        int n = strs.size();
        
        for(int i=0;i<n;i++){
            min_size = min(min_size, (int)strs[i].size());
        }
        
        string res = "";
        
        for(int i=0;i<min_size;i++){
            for(int j=0;j<n-1;j++){
                if(strs[j][i]!=strs[j+1][i]){
                    return res;
                }
            }
            res += strs[0][i];
        }
        
        return res;
    }
};