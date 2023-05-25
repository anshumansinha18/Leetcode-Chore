class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        
        int n = rectangles.size();
        unordered_map<double, int> m;
        
        for(int i=0;i<n;i++){
                double x = (double)rectangles[i][0]/rectangles[i][1];
                m[x]++;
        }
        
        long long sum=0;
        for(auto it: m){
            long long x = it.second;
            x--;
            sum+= (x*(x+1)/2);
        }
        
        return sum;
    }
};