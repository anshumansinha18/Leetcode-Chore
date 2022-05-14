class Solution {
public:
    int maxProfit(vector<int>& prices) {
          
        int n = prices.size();
        
        int l = 0;
        int r = 1;
        int max_diff = 0;
        while(r<n && l<r)
        {
            if(prices[l]>prices[r])
            {
                l=r;
                r++;
            }
            else
            {
                max_diff = max(max_diff, prices[r]-prices[l]);
                r++;
            }
        }
        
        return max_diff;
    }
};