class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int l=0;
        int r=l+1;
        
        int res=0;
        while(r<n){
           
            if(prices[l]>prices[r]){
                l=r;
                r++;
            }
            else{
                res = max(res, (prices[r]-prices[l]));
                r++;
            }
        }
        
        return res;
    }
};