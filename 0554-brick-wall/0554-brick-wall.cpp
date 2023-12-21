class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        vector<vector<int>> sum;
        int n = wall.size();
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<wall[i].size();j++){
                if(j==0) temp.push_back(wall[i][j]);
                else temp.push_back(temp[j-1]+wall[i][j]);
            }
            sum.push_back(temp);
        }
        
       unordered_map<int, int> m;
        for(int i=0;i<sum.size();i++){
            for(int j=0;j<sum[i].size()-1;j++){
                m[sum[i][j]]++;
            }
        }
        
        int maxFreq=0;
        for(auto it: m){
            if(it.second>maxFreq){
                maxFreq=it.second;
            }
        }
        return sum.size()-maxFreq;
    }
};