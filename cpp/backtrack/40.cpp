class Solution {
public:
    void backtracking(vector<int>& candidates, int target, int comeco, vector<vector<int>>& res, vector<int>& atual) {
        if (target == 0) {
            res.push_back(atual); // se bate com zero então deu certo a soma
            return;
        }

        for (int i = comeco; i < candidates.size(); i++) {
            if (candidates[i] > target) // aqui está ordenado, então logicamente os próximos serão maiores
                break;

            if (i > comeco && candidates[i] == candidates[i-1]) // duplicatas do mesmo nível da árvore
                continue;

            atual.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i+1, res, atual);
            atual.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> atual;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, res, atual);

        return res;
    }
};