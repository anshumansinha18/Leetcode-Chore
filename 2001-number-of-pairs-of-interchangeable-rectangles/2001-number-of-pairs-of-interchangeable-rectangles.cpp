class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> m;
        int n=rectangles.size();
        for(int i=0;i<n;i++){
            m[(double)rectangles[i][0]/rectangles[i][1]]++;
        }
        
      long long count=0;
        for(auto it: m){
            long long x = it.second;
            count+=((x-1)*x)/2;
        }
            
        
        return count;
    }
};