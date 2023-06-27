class Solution {
public:
    
    int findIndex(vector<int>& arr, int x){
       
         int low=0;
        int high=arr.size()-1;
        int n = arr.size();
        int index=0;
        int mid;
        while(low<=high){
             mid = low + (high-low)/2;
            
            if(arr[mid] == x){
                return mid;
            }
               
            else if(x>arr[mid]){
                low=mid+1;
            }
            else
                high=mid-1;
        }
        
        cout<<low<<high<<endl;
        
        if(low>=0 && low<=n-1 && high>=0 && high<=n-1){
            int a = arr[low];
            int b = arr[high];
             if((abs(a-x) < abs(b-x)) || (abs(a-x) == abs(b-x) && a<b))
                 return low;
            else return high;
        }else if(high>=0 && high<=n-1){
            return high;
        }else return low;
        
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
         
        int index = findIndex(arr, x);
        int i=index;
        int j=index;
        
        
        vector<int> res;
        
        while(res.size()<k){
            if(i==j){
                res.push_back(arr[i]);
                i--;
                j++;
            }else if(i<0 && j<n){
                res.push_back(arr[j]);
                j++;
            }else if(j>=n && i>=0){
                res.push_back(arr[i]);
                i--;
            }else if(i>=0 && j<n){
                int a=arr[i];
                int b=arr[j];
                if((abs(a-x) < abs(b-x)) || (abs(a-x) == abs(b-x) && a<b)){
                    res.push_back(a);
                    i--;
                }else{
                    res.push_back(b);
                    j++;
                } 
            }
        }
        
        sort(res.begin(), res.end());
         return res;
        
    }
};