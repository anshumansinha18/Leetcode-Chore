class Solution {
public:
    
    int partition(vector<string>&strs, int low, int high){
        
        int i=low-1;
        string pivot = strs[high];
        
        for(int j=low;j<high;j++){
            if(strs[j]<pivot){
                i++;
                swap(strs[i], strs[j]);
            }
            
        }
        
        swap(strs[i+1], strs[high]);
        return i+1;
    }
    
    void quickSort(vector<string>& strs, int low, int high){
        if(low>=high){
            return;
        }
        
        int pivotIndex = partition(strs, low, high);
        quickSort(strs, low, pivotIndex-1);
        quickSort(strs, pivotIndex+1, high);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        
        quickSort(strs, 0, n-1);
        string res="";
        int i=0;
        
        for(int i=0;i<n;i++){
            cout<<strs[i]<<" ";
        }
       
        while(i<strs[0].size() && i<strs[n-1].size() && strs[0][i]==strs[n-1][i]){
            res+=strs[0][i];
            i++;
        }
        
        return res;
    }
};