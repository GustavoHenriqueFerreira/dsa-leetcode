class Solution {
public:
    vector<vector<int>> res; // todos subconjuntos
    vector<int> vetorAtual; // subconjunto atual

    void backtracking(vector<int>& nums, int comeco) {
        res.push_back(vetorAtual); // atual ja é subconjunto válido

        for (int i = comeco; i < nums.size(); i++){ // comeco faz nao volta pra tras
            vetorAtual.push_back(nums[i]); // pega o atual
            backtracking(nums, i+1);  // recursao pra proximo elemento
            vetorAtual.pop_back(); // desfaz escolha
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};