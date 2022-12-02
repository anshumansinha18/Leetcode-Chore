class Solution {
public:
    
    int binarySearch(vector<int>& piles, int low, int high, int h){
        
        int ans = INT_MAX;
        int mid;
        while(low<=high)
        {
            mid = low+(high-low)/2;
            
            long long int sum_hours = 0;
            
            for(int i=0;i<piles.size();i++)
                sum_hours += ceil(piles[i]*1.0/mid);
            
            
            if(sum_hours<=h){
                high = mid-1;
                ans = min(ans, mid);
            }
            else{
                low = mid+1;
            }
        
        }
        
        return ans;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
         
        int max_el = INT_MIN;
        
        int n = piles.size();
        
        for(int i=0;i<n;i++)
           max_el = max(max_el, piles[i]);
    
        
        return binarySearch(piles, 1, max_el, h);
    }
};