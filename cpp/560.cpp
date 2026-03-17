class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map; // prefixo de soma, quantas vezes essa soma apareceu
        int soma = 0, res = 0;

        map[soma] = 1; // isso permite detectar subarrays que começam no índice 0

        for (int i = 0; i < nums.size(); i++) {
            soma += nums[i]; // atualizar soma
            int somaAntiga = soma - k;
            res += map[somaAntiga]; // verifica quantas vezes já apareceu uma soma prefixo igual a (soma - k)
            map[soma]++; // registrar soma
        }

        return res;
    }
};