class Solution {
public:
    
    void compare(vector<vector<int>> &res, vector<int> a, vector<int> b){
        
        if(a[1]<b[0]){
            res.push_back(b);
        }else{
            res[res.size()-1][0]=min(a[0], b[0]);
            res[res.size()-1][1]=max(a[1],b[1]);
        }
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            
            compare(res, res[res.size()-1], intervals[i]);
        }
        
        return res;
    }
};