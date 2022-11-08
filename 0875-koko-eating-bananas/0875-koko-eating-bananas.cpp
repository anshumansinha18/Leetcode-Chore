class Solution {
public:
    
    int findMax(vector<int>& piles){
        int largest = INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            largest = max(piles[i], largest);
        }
        
        return largest;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int largest = findMax(piles);
        
        
        int l = 1;
        int r = largest;
        int minK = INT_MAX;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            long long int sum=0;
            for(int i=0;i<piles.size();i++)
            {
                sum += ceil(1.0*piles[i]/mid);
            }
            
            if(sum<=h)
            {
                minK = min(mid, minK);
                r = mid-1;
            }
            else
                l = mid+1;
            
        }
        
        return l;
        
    }
};