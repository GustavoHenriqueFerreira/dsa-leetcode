class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lucro = 0;
        int precoCompra = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            precoCompra = min(precoCompra, prices[i]);
            lucro = max(lucro, prices[i] - precoCompra);
        }

        return lucro;        
    }
};