class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        
        int n = rectangles.size();
        map<pair<int, int>, int> m;
        long long sum=0;
        for(int i=0;i<n;i++){
               int gcd = __gcd(rectangles[i][0], rectangles[i][1]);
            
                   
                   m[make_pair(rectangles[i][0]/gcd, rectangles[i][1]/gcd)]++;
        }
        
      
        
        for(auto it: m){
            long long x = it.second;
            x--;
            sum+= (x*(x+1)/2);
        }
        
        return sum;
    }
};