class Solution {
public:
    
    int binarySearch(vector<int>& arr, int x){
        int low=0;
        int high=arr.size()-1;
        int mid=-1;
        while(low<=high){
             mid = low+(high-low)/2;
            
                
            if(arr[mid]==x) return mid;
            else if(x>arr[mid]) low=mid+1;
            else high=mid-1;
        }
        
        return mid;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int index = binarySearch(arr, x);
        cout<<index<<endl;
        int low;
        int high;
        
        if(index<=(arr.size()-1)/2){
            low=index;
            high=index+1;
        }else{
            low=index-1;
            high=index;
        }
        cout<<low<<" "<<high<<endl;
        vector<int> res;
        while(low>=0 && high<=arr.size()-1 && k>0){
      
            int a = arr[low];
            int b =arr[high];
            
            if(abs(a-x)<abs(b-x) || (abs(a-x)==abs(b-x) && a<b)){
                res.push_back(a);
                low--;
            }else{
                res.push_back(b);
                high++;
            }
                k--;
        }
        
        while(low>=0 && k>0){
           
            res.push_back(arr[low]);
            low--;
            k--;
        }
        
        while(high<=arr.size()-1 && k>0){
            res.push_back(arr[high]);
            high++;
            k--;
        }
        sort(res.begin(), res.end());
        return res;
    }
};