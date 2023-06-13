class Solution {
public:
    int partitionString(string s) {
        
        
        int i=0;
        unordered_map<int, int> m;
        int n = s.size();
        int count=0;
        
        while(i<n){
            if(m[s[i]]>0){
                count++;
                m.clear();
            }
            m[s[i]]++;
            i++;
        }
        
        return count+1;
    }
};