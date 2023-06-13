class Solution {
public:
    
    
    void compare(vector<vector<int>> &res, vector<int> a, vector<int> b){
        
        if(a[1]<b[0] || b[1]<a[0])
            res.push_back(b);
        else{
            res[res.size()-1][0]=min(a[0], b[0]);
            res[res.size()-1][1]=max(a[1], b[1]);
        }
    }
        
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
       
        vector<vector<int>> res;
        
        int i=0;
        
        if(n==0){
            res.push_back(newInterval);
            return res;
        }
        
        while(i<n && newInterval[0]>intervals[i][1]){
            res.push_back(intervals[i]);
            i++;
        }
        
        if(i<n){res.push_back(intervals[i++]);}
        compare(res, res[res.size()-1], newInterval);
               
        
        while(i<n){
            compare(res, res[res.size()-1], intervals[i++]);
        }
        
        sort(res.begin(), res.end());
        return res;
        
    }
};