class Solution {
public:
    
    int findIndex(vector<int>& arr, int x){
       
        int n=arr.size();
        
        int index = n-1;
        int i=0;
        while(i<n){
            if(x<=arr[i]){
                index = i;
                break;
            }
            i++;
        }
        
        if(arr[index]!=x && index-1>=0){
           int a=arr[index-1];
           int b=arr[index];
            
           if(abs(a-x)<abs(b-x) || (abs(a-x)==abs(b-x) && a<b))
               index--;
        }
        cout<<index<<endl;
        return index;
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