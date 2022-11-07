class Solution {
public:
    
    int checkRow(vector<vector<int>>matrix, int target){
        
        int i=0;
        int n = matrix[0].size();
        int index = 0;
        while(i<matrix.size()){
            
            if(target>matrix[i][n-1])
                i++;
            else{
                index=i;
                break;
            }
        }
        
        return index;
    }
    
    int binarySearch(vector<int>& arr, int l, int r, int data){
        if(l>r)
            return -1;
        
        int mid = l + (r-l)/2;
        
        if(arr[mid]==data)
            return mid;
        else if(data>arr[mid])
            return binarySearch(arr, mid+1, r, data);
        else
            return binarySearch(arr, l, mid-1, data);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int row = checkRow(matrix, target);
        
        vector<int> vec = matrix[row];
        
        int res = binarySearch(vec, 0, vec.size()-1, target);
      
        if(res!=-1) return true;
        else return false;
    
    }
};