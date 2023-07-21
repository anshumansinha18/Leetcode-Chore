class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int low=0;
        int high=matrix.size()-1;
        
        while(low<high){
            int mid = low+(high-low)/2;
            
            if(target>matrix[mid][0])
                low=mid+1;
            else
                high=mid;
        }
        
        if(matrix[low][0]==target) return true;
        else if(target<matrix[low][0]) low--;
        
        if(low<0) return false;
        
        
        int l=0;
        int h=matrix[low].size()-1;
        
        while(l<h){
            int mid = l+(h-l)/2;
            
            if(target>matrix[low][mid])
                l=mid+1;
            else
                h=mid;
        }
        
        return matrix[low][l]==target?true:false;
        
        
    }
};