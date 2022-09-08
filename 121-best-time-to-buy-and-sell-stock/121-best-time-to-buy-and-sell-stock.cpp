class Solution {
public:
    int maxProfit(vector<int>& prices) {
     
        int n = prices.size();
        int l=0;
        int r=l+1;
        
        int res_diff = 0;
        while(l<n && r<n)
        {
            int diff = prices[r]-prices[l];
            res_diff = max(res_diff, diff);
            
            if(prices[r]>=prices[l])
                r++;
            else
                l++;
        }
        
        return res_diff;
    }
};