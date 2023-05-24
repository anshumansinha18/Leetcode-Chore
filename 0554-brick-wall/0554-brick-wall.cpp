class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        vector<vector<int>> cumm(wall.size());
        
        unordered_map<int, int> m;
        
        for(int i=0;i<wall.size();i++){
            vector<int> temp(wall[i].size());
            for(int j=0;j<wall[i].size()-1;j++){
                if(j==0) temp[j] = wall[i][j];
                else temp[j] = temp[j-1] + wall[i][j];
                m[temp[j]]++;
            }
            cumm[i] = temp;
        }
        
        int maxL = 0;
        for(auto it: m){
            maxL = max(maxL, it.second);
        }
        
        return wall.size()-maxL;
    }
};