class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_price = prices[0];
        
        for(int i = 1; i < prices.size(); i++){
            res = max(res, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        
        return res;
    }
};
