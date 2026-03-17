class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lucro = 0;
        int compra = prices[0]; // setar valor pra nao da erro embaixo

        for (int i = 0; i < prices.size(); i++) {
            compra = min(prices[i], compra); // quero o menor valor de compra
            lucro = max(lucro, prices[i] - compra); // quero ve se eu vender agora é melhor do que vender antes, logo pega o maximo
        }

        return lucro;
    }
};